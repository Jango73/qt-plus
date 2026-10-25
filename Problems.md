# Bug & Fragility Hunt — 10 Classes (scoped review)

Classes (batch 1): `CAverager` (+ `CRollingAverager`), `CInterpolator`, `CRollingFiles`, `CSingleton` / `CSingletonPool`, `CLogger`.
Classes (batch 2, generalist): `CTimeSampler`, `CFastList`, `CLazyPointer`, `CFactory` (+ `CFactoryProductEnumerator`), `CXMLNode`.
Classes (batch 3, generalist): `QTree`, `CTextGenerator`, `CPIDController`, `CTracableMutex`, `CDumpable`.

Each item has a checkbox, a severity tag, a problem description, and a fix recommendation.

Severity scale:
- `Critical` — crash, memory corruption, data loss, or broken uniqueness guarantee. Fix first.
- `Major` — wrong behavior, silent failure, or race that triggers in normal use. Fix soon.
- `Minor` — perf cost, leak on the margins, API friction, or issue needing narrow conditions.
- `Cosmetic` — style, naming, or message quality with no behavioral impact.

Note: no purely `Cosmetic` item came out of these 15 classes; the weakest findings are tagged `Minor` instead of inventing cosmetic noise. Distribution: 11 Critical, 42 Major, 26 Minor, 0 Cosmetic.

---

## 1. `CAverager<T>` / `CRollingAverager<T>` — `source/cpp/CAverager.h`


- [x] [Critical] **1.1 Division by zero when `numSamples == 0`**
  Problem: both constructors accept any `int` (`CAverager.h:15,81`). `CRollingAverager(0)` makes `append()` divide by zero (`CAverager.h:108-109`). `CAverager` with `m_iMaxValues <= 0` degenerates to always-empty (append then immediately `remove(0)`).
  Fix reco: `Q_ASSERT`/throw or clamp in constructors, e.g. `m_iMaxValues = qMax(1, iMaxValues)` and same for `m_iNumSamples`.

- [ ] [Major] **1.2 `CRollingAverager::operator<<` returns the wrong type (`CAverager<T>&`)**
  Problem: `CRollingAverager::operator<<` (`CAverager.h:93`) is declared to return `CAverager<T>&`, but the class does not inherit from `CAverager<T>`. `return *this;` therefore cannot bind correctly. Any use of `rollingAverager << value` is a compile error at best, silent confusion at worst.
  Fix reco: change the signature to `CRollingAverager<T>& operator<<(const T& value)`.

- [ ] [Major] **1.3 `CRollingAverager::append` does integer division for integer `T`**
  Problem: `m_tAverage += value / m_iNumSamples;` (`CAverager.h:109`) truncates to `0` when `T=int` and `value < m_iNumSamples`. The average gets stuck near `0` and never converges.
  Fix reco: accumulate in `double` internally and cast back on `getAverage()`, e.g. keep a `double m_dAverage` and compute `m_dAverage += (double(value) - m_dAverage) / m_iNumSamples;`.

- [ ] [Minor] **1.4 `CAverager::getAverage` assumes `T(int)` and `operator/(T)` exist**
  Problem: `returnValue / T(count)` (`CAverager.h:64`) and `T(0)` (`CAverager.h:54,57`) fail or behave surprisingly for non-arithmetic `T` (e.g. `QPointF`, custom structs). Integer `T` also silently truncates the mean.
  Fix reco: constrain/document to arithmetic types (`static_assert(std::is_arithmetic<T>)`), or accumulate in `double` and provide a separate integer-rounded overload.

- [ ] [Minor] **1.5 `QVector::remove(0)` on every `append` is O(n)**
  Problem: `append()` (`CAverager.h:39-47`) shifts the whole vector once the window is full. Fine for `N=5`, costly if `m_iMaxValues` is large or on hot paths.
  Fix reco: use a ring buffer index (`QVector` + head offset, or `std::deque`) to get O(1) eviction.

---
## 2. `CInterpolator<T>` — `source/cpp/CInterpolator.h`


- [ ] [Major] **2.1 `addValue()` does not maintain sort order, but `getValue()` assumes sorted input**
  Problem: `addValue()` (`CInterpolator.h:71-74`) just appends. `getValue()` (`CInterpolator.h:83-113`) clamps to `[first, last]` and does a linear interval search. Unsorted inserts yield wrong interpolation/extrapolation with no warning.
  Fix reco: either insert sorted (`std::upper_bound`) or sort + validate on `getValue()`, and document the precondition.

- [ ] [Major] **2.2 Division by zero on duplicate `dInput`**
  Problem: `inputRange = input2 - input1; factor = (input - input1) / inputRange;` (`CInterpolator.h:96-102`). Two points with the same input give `0/0` → `NaN`/`inf`, propagated into `output`.
  Fix reco: guard `if (qFuzzyIsNull(inputRange)) { output = output1; break; }` and/or reject duplicates in `addValue()`.

- [ ] [Major] **2.3 Uninitialized `tOutput` in default `InterpolatorValue()`**
  Problem: default ctor (`CInterpolator.h:25-28`) sets `dInput = 0.0` but leaves `tOutput` default-initialized. For POD `T` this can be indeterminate if ever read.
  Fix reco: value-initialize: `InterpolatorValue() : dInput(0.0), tOutput(T()) {}`.

- [ ] [Minor] **2.4 Internal state exposed by non-const reference**
  Problem: `getValues()` returns `QVector<InterpolatorValue>&` (`CInterpolator.h:57`), and `count()`/`getValue()` are non-const. Callers can mutate/break invariants and the class cannot be used from `const` contexts.
  Fix reco: return `const QVector<...>&` + a mutable private accessor if needed, and mark `count()`/`getValue()` as `const`.

- [ ] [Minor] **2.5 Empty interpolator silently returns `T()`**
  Problem: `if (count == 0) return output;` (`CInterpolator.h:81`) returns a default value indistinguishable from a real result.
  Fix reco: document, `Q_ASSERT(!empty)`, or return `std::optional<T>` / add `bool tryGetValue(double, T*)`.

---
## 3. `CRollingFiles` — `source/cpp/File/CRollingFiles.h`, `source/cpp/File/CRollingFiles.cpp`


- [x] [Critical] **3.1 Return values of `copy()` / `remove()` ignored — silent data loss**
  Problem: rotation does `remove(target); copy(source → target)` (`CRollingFiles.cpp:101-105`) without checking success. If the copy fails (permissions, disk full), the target is already gone.
  Fix reco: check every return, abort/log on failure, and prefer `QFile::rename()` (atomic on same filesystem) over copy+remove.

- [ ] [Major] **3.2 Not thread-safe**
  Problem: no mutex; two concurrent `backup()` calls (e.g. via `CLogger::onTimeout` + manual call) can interleave remove/copy and corrupt the backup chain.
  Fix reco: add a `QMutex` around `backup()`, or document “call only from one thread” and enforce with `Q_ASSERT`.

- [ ] [Minor] **3.3 No validation of `m_iMaximumBackups <= 0` or empty file name**
  Problem: `backup()` (`CRollingFiles.cpp:72-119`) with `m_iMaximumBackups <= 0` skips both loops in a degenerate way and then copies to `"<name>.-1"`. Empty `m_sFileName` creates stray files like `".0"` in the CWD.
  Fix reco: early-return + warning if `m_sFileName.isEmpty()` or `m_iMaximumBackups <= 0`.

- [ ] [Minor] **3.4 Rotation by copy is O(total size × backups)**
  Problem: full file contents are copied on each rotation instead of renaming. Expensive for large logs.
  Fix reco: rotate with `rename()` from highest index down, then copy/rename the live file once.

---
## 4. `CSingleton<T>` / `CSingletonPool` — `source/cpp/CSingleton.h`, `source/cpp/CSingletonPool.h/.cpp`


- [x] [Critical] **4.1 `getInstance()` / `init()` race — double creation**
  Problem: `CSingletonPool::init()` (`CSingletonPool.cpp:14-20`) and the check-then-create in `getInstance()` (`CSingleton.h:28-37`) are unsynchronized. Two threads can both see “not present” and `new` two instances; one leaks and callers hold different “singletons”.
  Fix reco: guard with a `QMutex`/`std::call_once`, or use a function-local `static` (Meyers singleton) / `Q_GLOBAL_STATIC`.

- [x] [Critical] **4.2 `killInstance()` null-dereferences the pool**
  Problem: `killInstance()` (`CSingleton.h:41-50`) calls `s_pSingletons->contains(...)` without `init()`/null check. Calling it before any `getInstance()` crashes.
  Fix reco: null-check (and lock) before use: `if (!s_pSingletons) return;`.

- [ ] [Major] **4.3 Singleton is copyable**
  Problem: `CSingleton()` is `protected` but copy-ctor/assignment are implicitly public, so `*CLogger::getInstance()` can be copied, breaking uniqueness.
  Fix reco: `CSingleton(const CSingleton&) = delete; CSingleton& operator=(const CSingleton&) = delete;`.

- [ ] [Minor] **4.4 `typeid(T).name()` as map key is fragile**
  Problem: the key (`CSingleton.h:30,43`) is a compiler-specific mangled name, unstable across compilers/shared-library boundaries and unreadable in debug output.
  Fix reco: use an explicit stable key or `std::type_index`, and store a typed deleter instead of raw `void*`.

- [ ] [Minor] **4.5 Pool and instances never freed — leaks + destruction-order risk**
  Problem: `s_pSingletons` (`CSingletonPool.cpp:10`) is a leaked `new QMap`, and instances are only freed by manual `killInstance()`. Sanitizers report leaks; teardown order is undefined.
  Fix reco: document ownership, or register an `atexit`/`qAddPostRoutine` cleanup that deletes instances then the map.

---
## 5. `CLogger` — `source/cpp/CLogger.h`, `source/cpp/CLogger.cpp`


- [x] [Critical] **5.1 Chained-logger recursion: cycle = stack overflow; cross-thread = lock-order hazard**
  Problem: `log()` holds `m_tMutex` then calls `pLogger->log(...)` on each chained logger (`CLogger.cpp:351,362,373,384`). A cycle (A→B→A) recurses until stack overflow (`QRecursiveMutex` permits re-lock, hiding it). Two threads logging through opposite chains can also ABBA-deadlock.
  Fix reco: release the lock before forwarding (copy the chain list under lock), and/or add cycle detection / document “DAG only”.

- [ ] [Major] **5.2 `LOG_CRITICAL_TOKEN` macro is broken**
  Problem: `#define LOG_CRITICAL_TOKEN(a) ... log(llCritical,a,b)` (`CLogger.h:47`) declares one parameter `a` but references an undefined `b`. Any use fails to compile (copy-paste bug; siblings correctly use `(a,b)`).
  Fix reco: `#define LOG_CRITICAL_TOKEN(a,b) CLogger::getInstance()->log(llCritical,a,b)`.

- [ ] [Major] **5.3 Most setters and chained-list mutation are unlocked**
  Problem: `setDisplayTokens`, `setIgnoreTokens`, `setMaxFileSize`, `setBackupActive`, `register/unregisterChainedLogger`, `pathName()`, `maxFileSize()` (`CLogger.cpp:123-175`, `CLogger.cpp:245-258`) touch shared state without `QMutexLocker`, while `log()`/`filterToken()` read it under lock → data races.
  Fix reco: lock every accessor/mutator with the same mutex (or make config immutable after `initialize()`).

- [ ] [Major] **5.4 `initialize()` / `log()` ignore `QFile::open()` failure and silently drop logs**
  Problem: `m_pFile->open(...)` return value is unchecked (`CLogger.cpp:237,506`). If it fails, `log()`’s `if (m_pFile && m_pFile->isOpen())` (`CLogger.cpp:323`) just drops everything.
  Fix reco: check `open()`, keep last error (`m_pFile->errorString()`), emit `qWarning()`, and optionally fall back to stderr.

- [ ] [Major] **5.5 `m_iFileSize += write(...)` corrupts the counter on failure + lossy encoding**
  Problem: `write()` returns `-1` on error, which is added to `m_iFileSize` (`CLogger.cpp:331,340,349,...`), shrinking it. `toLatin1().constData()` also calls the `write(const char*)` overload (strlen semantics, truncates embedded NULs) and mangles non-Latin text.
  Fix reco: capture to a `QByteArray ba = ...toUtf8(); qint64 n = m_pFile->write(ba); if (n > 0) m_iFileSize += n;` and handle `n == -1`.

- [ ] [Major] **5.6 Rotation uses an in-memory size counter, blocks loggers during I/O**
  Problem: `onTimeout()` (`CLogger.cpp:486-510`) and `initialize()` (`CLogger.cpp:220-223`) do file close/`backup()`/reopen while holding `m_tMutex`, stalling all logging threads; the size trigger relies solely on `m_iFileSize`, which drifts after restarts/external writes.
  Fix reco: compare against `QFile::size()` (or refresh the counter at open), and do rotation outside the hot lock or on a dedicated thread.

- [ ] [Minor] **5.7 Default ctor assumes a `QCoreApplication` exists**
  Problem: `CLogger()` (`CLogger.cpp:27-28`) dereferences `QCoreApplication::applicationFilePath()/applicationDirPath()` unconditionally. Without an app instance (tests, libs) the path is empty and the logger writes to an unintended location.
  Fix reco: guard with `qApp` null check and fall back to `QDir::currentPath()/tempPath()` + `qWarning()`.

---
## 6. `CTimeSampler` — `source/cpp/CTimeSampler.h`, `source/cpp/CTimeSampler.cpp`

- [x] [Critical] **6.1 `dumpAccumulatedTimes()` iterates shared maps with no lock**
  Problem: `dumpAccumulatedTimes()` (`CTimeSampler.cpp:97-117`) reads `m_mStartTimes` / `m_mAccumTimes` / `m_mNumCalls` with no locking, while `startSample()` / `stopSample()` mutate them on other threads. `QMap` is not thread-safe: iteration during insert is undefined behavior and can crash.
  Fix reco: take a snapshot copy of the maps under lock, release the lock, then format + log from the snapshot.

- [ ] [Major] **6.2 `stopSample` / `stopSampleAndLog` check `contains()` outside the lock (TOCTOU)**
  Problem: the existence check on `m_mStartTimes` (`CTimeSampler.cpp:65,81`) runs before `m_tMutex.lock()`. A concurrent `startSample()` can mutate the maps in between, so the subsequent `m_mStartTimes[sName]` / `m_mAccumTimes[sName]` can insert default entries or read a half-updated state.
  Fix reco: move the `contains()` check inside the locked region (or use `QMutexLocker` for the whole method).

- [ ] [Major] **6.3 Logging while holding the sampler mutex (lock-order inversion)**
  Problem: `stopSampleAndLog()` calls `m_pLogger->log(...)` while still holding `m_tMutex` (`CTimeSampler.cpp:90-92`). A slow logger (file I/O, rotation) stalls all samplers, and if the logger ever calls back into the sampler the lock ordering inverts (sampler → logger vs logger → sampler).
  Fix reco: compute `msecs` under lock, unlock, then log. Same for `dumpAccumulatedTimes()`.

- [ ] [Minor] **6.4 Unbounded map growth — start entries are never removed**
  Problem: every new `sName` adds permanent entries to `m_mStartTimes` / `m_mAccumTimes` / `m_mNumCalls`; nothing ever erases them. Long-running apps with dynamic names (e.g. per-file or per-request labels) leak memory slowly.
  Fix reco: add an explicit `clear(name)` / `reset()` API, or document that names must come from a small fixed set.

- [ ] [Minor] **6.5 Wall-clock (`QDateTime`) used for durations + division hazards in dump**
  Problem: durations use `QDateTime::currentDateTime()` + `msecsTo()` (`CTimeSampler.cpp:49,70,86`), which has coarse resolution and jumps on NTP/ DST adjustments. In the dump, `m_mAccumTimes[sName]` uses non-const `operator[]` (inserts `0` on miss) and `... / m_mNumCalls[sName]` can divide by zero if the count entry is missing, yielding `inf`.
  Fix reco: use `QElapsedTimer` for durations; in the dump use `value(key, default)` lookups and guard `numCalls == 0`.

## 7. `CFastList<K, T>` — `source/cpp/CFastList.h`

- [x] [Major] **7.1 Public inheritance from `QList<T>` breaks the list/hash invariant**
  Problem: `CFastList` extends `QList<T>` publicly (`CFastList.h:15`), so any caller can use `append()`, `removeAt()`, `clear()`, etc. directly and bypass `m_hLookup`. The hash then silently disagrees with the list.
  Fix reco: favor composition over inheritance (hold a `QList<T>` member), or inherit privately and expose only a safe API.
  Fixed: private inheritance with a `using`-exposed read-only vocabulary plus iteration; mutating QList entry points no longer compile. This exact defect caused a use-after-free crash in cutegit (`unload()` cleared the list without the hash).

- [x] [Major] **7.2 `removeItem(key, item)` leaves dangling keys for shared values**
  Problem: `removeItem(K, const T&)` (`CFastList.h:42-46`) removes *all* list entries equal to `item` but only erases the one key. Other keys mapping to the same value now point at values no longer in the list.
  Fix reco: remove only the entry associated with the key, or rebuild/validate the affected hash entries and document the duplicate-value policy.
  Fixed: single-key removal erases one list occurrence plus its hash entry, other keys sharing the value stay valid; the two-argument overload only removes when the key holds the given item.

- [x] [Major] **7.3 `itemByKey()` silently default-constructs on miss**
  Problem: `return m_hLookup[key];` (`CFastList.h:53-56`) inserts and returns a default `T()` when the key is absent. Callers cannot tell "missing" from "stored default", and the hash grows on every typo.
  Fix reco: return `std::optional<T>` / take a `bool* found` out-param, or at least use `value(key)` without insertion plus a `containsKey()` precondition (and make accessors `const`).
  Fixed: `value(key)` without insertion, accessors made `const`; documented `containsKey()` precondition.

- [x] [Minor] **7.4 `deleteAll()` assumes `T` is a pointer, without constraint**
  Problem: `qDeleteAll(*this)` (`CFastList.h:58-63`) only compiles when `T` is a pointer type, but nothing states it. For non-pointer `T` users get a cryptic template error far from the cause.
  Fix reco: `static_assert(std::is_pointer<T>::value, ...)` on `deleteAll()`, or split into a pointer specialization.
  Fixed: `static_assert` with an explicit message.

- [ ] [Minor] **7.5 No thread-safety, underspecified key requirements**
  Problem: list + hash are mutated with no locking, and `K` needs `qHash()`/`operator==` without this being documented. Concurrent `addItem` / `removeItem` corrupts both containers.
  Fix reco: document `K` requirements and single-threaded use, or add a mutex around every mutating/reading method.

## 8. `CLazyPointer<dataType>` — `source/cpp/CLazyPointer.h`

- [x] [Critical] **8.1 Copy shares ownership of the same raw pointer → double-free**
  Problem: the copy ctor and `operator=` copy `m_pData` verbatim (`CLazyPointer.h:30-33,104-111`), so two objects believe they own the same pointer. Both `delete` it in `~CLazyPointer()` (`CLazyPointer.h:36-39`) → double-free / heap corruption. Mutation through one copy also surprises the other.
  Fix reco: delete copy semantics, or implement deep-copy / shared ownership (`QSharedPointer` / `std::shared_ptr`) with documented policy.

- [ ] [Major] **8.2 `const` accessors are broken: `get() const` cannot compile when used, `operator*()/->() const` can null-deref**
  Problem: `get() const` (`CLazyPointer.h:61-67`) calls non-const `loadData()`, so any real `const` use is a compile error. Conversely the `const` `operator*` / `operator->` (`CLazyPointer.h:86-102`) skip lazy loading entirely (the code comment itself admits it: "might dereference NULL pointer if unset").
  Fix reco: mark `m_pData`/`m_pInstantiator`/`m_pContext` `mutable` and make `loadData()` `const`, or remove the `const` overloads until lazy-load-from-const is properly designed.

- [ ] [Major] **8.3 `isNull()` has side effects — it instantiates the object**
  Problem: `isNull()` (`CLazyPointer.h:69-75`) calls `loadData()` when empty, so a mere null check triggers allocation (and arbitrary user code in the instantiator). A null-returning instantiator also means *every* `isNull()` call re-runs the factory.
  Fix reco: make `isNull()` a pure check (`return m_pData == nullptr;`) and add a separate `ensureLoaded()` / `load()` method.

- [ ] [Major] **8.4 `set()` / `loadData()` lack null and self-assignment guards**
  Problem: `loadData()` (`CLazyPointer.h:130-134`) dereferences `m_pInstantiator` unchecked (crash if null), and `set(pData)` (`CLazyPointer.h:47-51`) does `delete m_pData; m_pData = pData;` — passing the already-owned pointer (`set(ptr.get())`) deletes the very object it stores (use-after-free).
  Fix reco: `Q_ASSERT`/early-return on null instantiator, and `if (pData != m_pData)` guard in `set()` with documented ownership transfer.

- [ ] [Major] **8.5 Not thread-safe — concurrent `get()` double-creates and leaks**
  Problem: `get()` / `operator->` check-then-create with no lock. Two threads can both see `nullptr`, both call the instantiator, one result leaks and callers may hold different pointers.
  Fix reco: guard load with a mutex (double-checked locking) or document single-threaded use.

## 9. `CFactory<T>` (+ `CFactoryProductEnumerator<T>`) — `source/cpp/CFactory.h`

- [ ] [Major] **9.1 Registry is per-instance despite the `s_v` (static-like) name**
  Problem: `s_vInstanciators` (`CFactory.h:76`) is a plain instance member. Registering on one factory instance and instantiating on another silently returns `nullptr` (`CFactory.h:44-52`), which is easy to misread as "unknown class".
  Fix reco: rename to `m_...`, document instance-scoped registries, or make the registry explicitly shared/static if that is the intent.

- [ ] [Major] **9.2 Enumerator holds a raw, unchecked factory pointer and re-snapshots keys per call**
  Problem: `CFactoryProductEnumerator` stores `m_pFactory` without null or lifetime checks (`CFactory.h:92-96,122`). `next()` (`CFactory.h:103-114`) rebuilds `keys()` on every call (O(n log n)) and indexes into it, so registering mid-enumeration shifts indices (skips/repeats products). Order is `QMap` sorted order, not registration order, which surprises callers.
  Fix reco: null-check + document lifetime ("factory must outlive enumerator"), snapshot the key list once in the ctor, and document sorted-order semantics.

- [ ] [Minor] **9.3 `registerProduct()` silently overwrites duplicates**
  Problem: `s_vInstanciators[sClassName] = pInstanciator;` (`CFactory.h:38-41`) replaces an existing entry with no warning. Typos/double registration change behavior invisibly.
  Fix reco: return `bool` (false if already present) and/or `qWarning()` on overwrite; add an `unregisterProduct()` mate.

- [ ] [Minor] **9.4 `instanciateProduct()` failure is a bare `nullptr` with no diagnostics**
  Problem: unknown names return `nullptr` with no log or error enum. Every caller must remember the null check; a missed check crashes far from the cause.
  Fix reco: keep the `nullptr` contract but document it prominently, and add a `bool contains(className) const` / `QStringList registeredProducts() const` helper for validation.

- [ ] [Minor] **9.5 No thread-safety for register-vs-instantiate races**
  Problem: `registerProduct()` mutates the `QMap` while `instanciateProduct()` / `next()` read it. Concurrent use is a data race on `QMap` internals.
  Fix reco: add a `QReadWriteLock` (write on register, read on instantiate/enumerate) or document external synchronization.

## 10. `CXMLNode` — `source/cpp/CXMLNode.h`, `source/cpp/CXMLNode.cpp`

- [x] [Major] **10.1 All load/parse failures collapse to an empty node — no error signal**
  Problem: missing files, `open()` failures, bad XML (`setContent()` false), and bad JSON all returned a default `CXMLNode()` (`CXMLNode.cpp:139-155,192-256,304-319,388-400`). The `QDomDocument` error string and `QJsonParseError` were discarded, so callers could not distinguish "file missing" from "malformed content". Fixed: `load()`, `loadXMLFromFile()`, `loadXMLCFromFile()`, `loadJSONFromFile()`, `parseXML()` and `parseJSON()` take an optional `QString* pErrorString` (default `nullptr`, existing callers unchanged) and forward file errors plus parser line/column/offset details.
  Fix reco: add `bool ok` out-params / `QString* errorString` overloads (or a `CXMLResult` type), and forward the underlying parse error details.

- [x] [Major] **10.2 `parseXMLNode()` pollutes children with whitespace `#text` nodes**
  Problem: only the single-child `#text` case was collapsed (`CXMLNode.cpp:277-287`). Pretty-printed XML (multiple children + indentation) fell into the `else` branch and appended whitespace text nodes as real children, breaking `getNodeByTagName()` counts and round-trips. Fixed: whitespace-only text nodes are skipped during child iteration.
  Fix reco: skip whitespace-only text nodes (`node.isText()` + `trimmed().isEmpty()`) during child iteration.

- [x] [Major] **10.3 JSON conversion is lossy: scalars flattened, non-object array items dropped**
  Problem: numbers/bools became string attributes via `toString()` (`CXMLNode.cpp:357-360`), losing types — worse, `QJsonValue::toString()` returns empty for non-strings, so values were wiped entirely. `parseJSONArray()` called `toObject()` on every element (`CXMLNode.cpp:375-378`), so arrays of scalars became empty `"NOTAG"` nodes. Top-level arrays were dropped entirely since `parseJSON()` only read `doc.object()` (`CXMLNode.cpp:394-396`). Fixed: scalars go through `toVariant().toString()` (values preserved as text; string coercion is now documented on `parseJSON()`), scalar array items become value nodes, and top-level arrays parse under a `NOTAG` root instead of being dropped.
  Fix reco: preserve types (store numbers/bools distinctly or document string coercion), handle `isArray()` at top level, and convert scalar array items to value nodes instead of empty objects.

- [x] [Major] **10.4 Empty tag silently drops the whole subtree on export**
  Problem: `toQDomElement()` created an element from `m_sTag` (`CXMLNode.cpp:439-463`); with an empty tag the element was null and children were silently discarded (lost data on `toString()`/`saveXMLToFile()`). Fixed: `toQDomElement()` emits a `qWarning()` on empty tag instead of failing silently, and `toQDomDocument()` serializes children fragment-style at document level when the root tag is empty.
  Fix reco: `Q_ASSERT`/warning on empty tag, or serialize children fragment-style instead of dropping them.

- [ ] [Minor] **10.5 File I/O ignores races and partial writes**
  Problem: loaders do `exists()` then `open()` (TOCTOU, `CXMLNode.cpp:196,221,244`); savers ignore `QFile::write()` return values (`CXMLNode.cpp:553-610`), so short writes (disk full) still report success. Byte decoding uses implicit `QString(QByteArray)` conversions instead of explicit `fromUtf8()`.
  Fix reco: drop the `exists()` pre-check (just `open()` and report errors), check write byte counts, and decode/encode explicitly with UTF-8.

---

## 11. `QTree<T>` — `source/cpp/QTree.h`, `source/cpp/QTree.cpp`

- [x] [Critical] **11.1 `removeAt()` / `removeAll()` leave dangling parent pointers (UAF under Qt6)**
  Problem: children live by value in `QList<QTree<T>>` (`QTree.h:366`), which is contiguous storage under Qt6 (this repo builds against Qt6, `CMakeLists.txt:113-121`). `removeAt()` (`QTree.h:168-171`) and both `removeAll()` overloads (`QTree.h:174-202`) shift elements without ever calling `assignParents()` — unlike every `append()` overload (`QTree.h:144-165`). The user-declared copy ctor (`QTree.h:36-41`) suppresses implicit moves, so the shift copies subtrees whose grandchildren keep `m_pParent` aimed at the pre-shift (now dead) addresses. Any later `root()` / `position()` / `moveNode()` / `path()` walk through them is a use-after-free. Qt5's pointer-array `QList` masked this; the Qt6 build does not.
  Fix reco: call `assignParents(this, m_pParent)` at the end of every structural mutator, or store children as pointers (`QList<QTree<T>*>`) with explicit ownership.

- [x] [Critical] **11.2 `path()` does not compile: `m_Parent` vs `m_pParent`**
  Problem: `path()` walks `node = node->m_Parent;` (`QTree.h:294`), but the member is declared `m_pParent` (`QTree.h:365`). Any instantiation of `path()` is a hard compile error, so the documented API (`QTree.cpp:192-195`) is unusable. The header also only includes `<QList>` (`QTree.h:8`) while `path()`/`flatValues()` need `QStringList`/`QVector`/`QString`, relying on transitive includes.
  Fix reco: rename to `m_pParent`, add the missing includes, and add a compile test instantiating `QStringTree::path()`.

- [ ] [Major] **11.3 Copy ctor copies dangling parent pointers; no copy-assignment**
  Problem: the copy ctor (`QTree.h:36-41`) copies `m_pParent` verbatim and `m_vChildren` by value, so each copied child keeps a `m_pParent` pointing into the *source* tree, not the new parent. There is no `operator=`, so the default assignment has the same flaw. `root()` (`QTree.h:117-127`), `position()` and `moveNode()` on a copy then walk into the original tree — dangling once the source dies.
  Fix reco: after copying children, call `assignParents(this, m_pParent)` (or `nullptr` for a detached root); define `operator=` with the same fix (rule of three) or `= delete` it.

- [ ] [Major] **11.4 `moveNode()` matches by value and has no cycle check**
  Problem: `moveNode()` (`QTree.h:206-233`) `append()`s a copy of the node, then removes the original via `removeAll(nodeToMove)` which compares only `value()` (`QTree.h:187-202`). Siblings with an equal value are over-deleted. Moving an ancestor under one of its own descendants is not refused: `assignParents()` then recurses forever and `root()` never terminates.
  Fix reco: remove by node identity (index/pointer), not by value; refuse the move when `newParentNode` is inside `nodeToMove`'s subtree.

- [ ] [Major] **11.5 Parent invariant is bypassable; identity confused with equality**
  Problem: `getChildren()` returns a mutable `QList<QTree<T>>&` (`QTree.h:99-102`), so callers can `append()`/`clear()` without `assignParents()`, leaving stale `m_pParent` links (same family as 7.1). `position()` (`QTree.h:281-283`) locates `*this` via `indexOf(*this)`, but `operator==` compares only `m_tValue` (`QTree.h:249-251`), returning the first *equal-valued* sibling instead of self. `removeAt()` (`QTree.h:169-171`) and `operator[]` (`QTree.h:274-277`, no `const` overload) have no bounds check.
  Fix reco: return a `const` list + dedicated mutators that maintain parents; compare identity (`&child == this`) in `position()`; bounds-guard `removeAt`/`operator[]` and add a `const` `operator[]`.

- [ ] [Major] **11.6 Raw interior pointers with no stability contract**
  Problem: `nodeForValue()` returns `&(m_vChildren[index])` (`QTree.h:318-336`); `parent()` / `root()` expose `m_pParent` (`QTree.h:93-96,117-127`); `operator[]` / `value()` hand out interior references (`QTree.h:274-277,81-90`). Any later `append()` (realloc) or removal invalidates them, and no vector-style invalidation rule is documented. Held node pointers silently dangle across normal mutations.
  Fix reco: document that any structural mutation invalidates outstanding node pointers, add `const` navigation overloads, or navigate by index instead of raw pointer.

- [ ] [Major] **11.7 The `(value, parent)` ctor never attaches to the parent**
  Problem: `QTree(T value, QTree<T>* parent)` (`QTree.h:29-33`) only stores the back-pointer; the new node is *not* appended to the parent's children. The node claims a parent that doesn't contain it: `parent()` is non-null but `position() == -1`, and it is invisible to `contains()` / `flatValues()` / `nodeForValue()`.
  Fix reco: attach in the ctor or drop the `parent` parameter and force explicit `append()`.

- [ ] [Major] **11.8 `append(QTree<T>*)` dereferences without a null check**
  Problem: `m_vChildren.append(*node)` (`QTree.h:160-165`) crashes on `nullptr`, while the sibling overloads null-check (`removeAll(node)` at `QTree.h:189`, `moveNode()` at `QTree.h:214,220`). Inconsistent guards turn a typo into a crash instead of a no-op.
  Fix reco: `if (!node) { Q_ASSERT(false); return; }`, matching the siblings.

- [ ] [Minor] **11.9 Surprising traversal semantics + O(n) insert**
  Problem: every `append()` re-walks the *whole* tree via `assignParents(root(), nullptr)` (`QTree.h:144-165,338-346`) — O(n) per insert, O(n²) to build. `flatValues()` starts from `root()`, not `this` (`QTree.h:130-137`), so a subtree call returns the whole tree. `contains()` skips self (`QTree.h:236-245`). Deep trees recurse unboundedly in `recursiveCount_internal`/`nodeForValue_internal`/`flatValues_Recurse` (stack overflow risk).
  Fix reco: fix parents locally on append (set the new child's chain only); document/fix `flatValues()` origin; check self in `contains()`; note the recursion limit.

- [ ] [Minor] **11.10 `const` broken by `root()`'s `const_cast`; asymmetric contracts**
  Problem: `root() const` returns a mutable pointer via `const_cast` (`QTree.h:117-127`), so a `const QTree` can be mutated through it — while `nodeForValue()` and `operator[]` have no `const` overloads at all, so `const` callers can't even navigate. Separately: `removeAll()` is shallow-only (direct children, `QTree.h:174-202`) while `contains()` descends (`QTree.h:236-245`), so deep duplicates survive a "removeAll"; and `path()` stringifies via `QVariant::fromValue()` (`QTree.h:296`), so `T` must be QVariant-convertible — document the requirement.
  Fix reco: provide a `const`/non-`const` `root()` pair without casts, add `const` navigation overloads, document (or recurse) `removeAll()`, and document the QVariant-convertible requirement of `path()`.

---

## 12. `CTextGenerator` — `source/cpp/CTextGenerator.h`, `source/cpp/CTextGenerator.cpp`

- [ ] [Major] **12.1 `capitalize()` indexes `[0]` without an empty check**
  Problem: `capitalize()` does `sReturnValue[0].toUpper()` (`CTextGenerator.cpp:118-123`). On an empty string this is an out-of-bounds access (assert in debug, UB/crash in release). `getWord()` currently can't return empty, but any subclass/empty-table edit or direct reuse makes it reachable.
  Fix reco: `if (sText.isEmpty()) return sText;` first.

- [ ] [Major] **12.2 `std::rand()` never seeded, process-global, biased by `CLIPPED`**
  Problem: `randomDouble()` (`CTextGenerator.cpp:111-114`) uses `std::rand()` with no `srand()` — same sequence every run — shares global state (not thread-safe), and clips to `[0.00, 0.99]`, so `floor(r * count)` (`CTextGenerator.cpp:129,135-137`) never selects the last ~1% of entries, on top of classic modulo/floor bias.
  Fix reco: use `QRandomGenerator::global()->generateDouble()` (or a per-instance generator), drop `CLIPPED`.

- [ ] [Minor] **12.3 Negative `length` silently accepted**
  Problem: `sentence()`/`paragraph()`/`text()` treat `0` as "random default" but accept negatives without complaint (`CTextGenerator.cpp:60-107`): the loop is skipped and a single-word result is returned, hiding caller bugs.
  Fix reco: `Q_ASSERT(length >= 0)` and/or clamp (`qMax(0, length)`), documented.

- [ ] [Minor] **12.4 `getWord()` has no empty-table guard**
  Problem: `getWord()` indexes `m_vWordLengths[...]`, `m_vSyllableCounts[...]`, `m_lSyllables[...]` (`CTextGenerator.cpp:127-142`) unconditionally. The vectors are `protected` (`CTextGenerator.h:67-69`), so a subclass clearing them turns every call into an OOB crash.
  Fix reco: `Q_ASSERT(!...isEmpty())` + early-return `QString()`.

- [ ] [Minor] **12.5 Two draws for one ending; API always capitalized, never `const`**
  Problem: the ending calls `randomDouble()` twice (`CTextGenerator.cpp:64`), making the `!`/`?` split hard to reason about. `word()` always capitalizes (`CTextGenerator.cpp:52-55`), so there is no lowercase-word API, and all generators are non-`const` (`CTextGenerator.h:36-60`) though the state is logically unchanged.
  Fix reco: single draw (`double r = randomDouble();`), add a `lowerWord()` or flag, mark read-only methods `const` once the RNG is a member.

---

## 13. `CPIDController` — `source/cpp/CPIDController.h`, `source/cpp/CPIDController.cpp`

- [ ] [Major] **13.1 Division by zero when `dDeltaTimeMillis == 0`**
  Problem: `m_dDerivative = (m_dError - m_dPreviousError) / DeltaTimeMillis;` (`CPIDController.cpp:69`). A zero delta (first call, coarse timer, paused loop) yields `inf`/`NaN`, which poisons `m_dOutput` and latches via `m_dPreviousError`.
  Fix reco: guard `if (DeltaTimeMillis <= 0) { /* hold output, skip D/I update */ return; }`.

- [ ] [Major] **13.2 Unbounded integral (windup) scaled in milliseconds**
  Problem: `m_dIntegral += m_dError * DeltaTimeMillis;` (`CPIDController.cpp:66`) accumulates forever with ms units, so the `I` term is 1000× what a seconds-based tuning expects and winds up during saturation, causing large overshoot and slow recovery.
  Fix reco: integrate in seconds, clamp `m_dIntegral` (anti-windup), and document the time unit next to the gains.

- [ ] [Major] **13.3 `reset()` also wipes the setpoint; no output limits or `NaN` guard**
  Problem: `reset()` zeroes `m_dSetPoint` together with the state (`CPIDController.cpp:43-51`), so re-arming the controller silently drops the target. There is no output saturation and no finite-value check, so one `NaN` input latches the controller forever.
  Fix reco: keep `reset()` state-only (separate `setSetPoint(0)` if wanted), add `setOutputLimits(min, max)`, ignore/replace non-finite inputs.

- [ ] [Minor] **13.4 Racy, kick-prone update with no filtering**
  Problem: `update()` races with the `set*()` setters (`CPIDController.h:27-36`) under threads; the D term differentiates the setpoint error, so setpoint steps kick the output; no derivative filtering or sample-time clamping.
  Fix reco: document single-threaded use (or add a mutex), consider derivative-on-measurement, clamp `dt` to `[dtMin, dtMax]`.

---

## 14. `CTracableMutex` — `source/cpp/CTracableMutex.h`, `source/cpp/CTracableMutex.cpp`

- [x] [Critical] **14.1 Copy ctor / assignment silently break mutual exclusion**
  Problem: both are no-ops (`CTracableMutex.cpp:21-28`, declared `CTracableMutex.h:27,37`): the copy gets a fresh unlocked `QRecursiveMutex` and drops `m_sName`/trace state. Code that copies a mutex (containers, captures) then guards shared data with different copies has *no* mutual exclusion at all (same family as 4.3/8.1).
  Fix reco: `CTracableMutex(const CTracableMutex&) = delete;` + `operator=` `= delete;`.

- [x] [Critical] **14.2 `lock()` can return `false` without holding the lock**
  Problem: `lock()` does `tryLock(5000)` and returns `false` on timeout (`CTracableMutex.cpp:45-81`). Unlike `QMutex::lock()`, failure leaves the critical section unprotected, and any caller ignoring the `bool` (or using `QMutexLocker`, which expects `void lock()`) silently runs unlocked. It is also incompatible with `QMutexLocker<CTracableMutex>`.
  Fix reco: retry until acquired (with warnings), or assert/abort on timeout; document that `false` means "not locked, do not proceed".

- [x] [Major] **14.3 Lock-trace stack is pushed on failure, popped on every `unlock()`**
  Problem: `m_sLockNames.append(...)` ran only inside the *failure* branch (old `CTracableMutex.cpp:65`); the success path recorded nothing. `unlock()` unconditionally popped, draining entries owned by other failures, while a timed-out caller that still called `unlock()` unlocked a mutex it never locked. Fixed as a side effect of 14.2: the timeout path loops instead of returning unlocked and no longer pushes phantom entries, so `lock()` returns only when held and every `unlock()` is balanced. Residual: `m_sLockNames` is now write-never (vestigial) — see 14.5.
  Fix reco: push `{thread, sName, timestamp}` on success, pop only the matching entry, and never `unlock()` after a failed `lock()`.

- [ ] [Major] **14.4 Shared trace state without synchronization; 64-bit thread-ID truncation**
  Problem: the static `m_vThreadNames` (`CTracableMutex.cpp:11`, `CTracableMutex.h:63`) and per-instance `m_sLockNames` are read/mutated with no lock (`CTracableMutex.cpp:55,65,72-75,89,99-103`) — the tracer itself races. Thread IDs are truncated via `(int)((qlonglong)QThread::currentThreadId())` (`CTracableMutex.cpp:51,85`), colliding on 64-bit.
  Fix reco: guard with a static `QMutex`, store `quintptr`/`Qt::HANDLE` keys (or `QThread::currentThread()`), or drop the global registry.

- [ ] [Minor] **14.5 Wall-clock timing, always-on trace macro, public mutex**
  Problem: elapsed time uses `QDateTime::currentDateTime()` (`CTracableMutex.cpp:47,83`), which jumps on NTP adjustments (same family as 6.5) — use `QElapsedTimer`. `#define FULL_MUTEX_TRACE` is forced in the header (`CTracableMutex.h:13`, with a French "comment out in release" note), penalizing every translation unit. `m_tMutex`/`m_sName` are public (`CTracableMutex.h:60-61`), letting callers bypass tracing. `m_sLockNames` is now vestigial (nothing pushes since 14.2/14.3) — remove it or record real ownership.
  Fix reco: `QElapsedTimer`, move the flag to the build system, make members private with accessors.

---

## 15. `CDumpable` — `source/cpp/CDumpable.h`, `source/cpp/CDumpable.cpp`

- [ ] [Major] **15.1 Base `dump()` is a silent no-op instead of pure virtual**
  Problem: `CDumpable::dump()` discards both arguments (`CDumpable.cpp:23-27`). A subclass forgetting the override dumps nothing with no diagnostic (same silent-failure family as 10.1).
  Fix reco: `virtual void dump(QTextStream& stream, int iIdent) = 0;`.

- [ ] [Major] **15.2 Process-wide mutable `m_bJavaStyle` flag races**
  Problem: `static bool m_bJavaStyle` (`CDumpable.h:58`, `CDumpable.cpp:7`) flips `{`/`[` placement for *all* objects from any thread with no synchronization — concurrent dumps can mix styles nondeterministically.
  Fix reco: make it per-instance (or `std::atomic<bool>`), set it once at startup and document it.

- [ ] [Minor] **15.3 Hardcoded `"\r\n"` line endings; stream errors ignored**
  Problem: `dumpNewLine()` writes `"\r\n"` (`CDumpable.cpp:84-87`), wrong on Linux/macOS and noisy in diffs/tests. No method checks `stream.status()`, so failed writes still report success.
  Fix reco: write `"\n"` (or `Qt::endl`), check `stream.status()` on IO paths.

- [ ] [Minor] **15.4 By-value strings, unguarded indent, O(indent) spaces**
  Problem: helpers take `QString sText` by value (`CDumpable.h:42-52`), copying on every line. `dumpIndentedNoNewLine()` (`CDumpable.cpp:91-99`) loops `iIdent * 4` without guarding negative/huge `iIdent`, emitting one `<< " "` per column.
  Fix reco: `const QString&`, `iIdent = qMax(0, iIdent)`, emit a cached space run (`QString(4*iIdent, ' ')`).
