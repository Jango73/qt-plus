# qt-plus Usage Report — downstream repos

Survey of real-world usage of the 15 `Problems.md` classes in 4 downstream repos
(`cutegit`, `aze`, `quick3d`, `vips`), vendored `qt-plus/` copies excluded.
Counts = files (`.cpp`/`.h`) referencing the class, include or usage.

## Per-class usage

| Class | cutegit | aze | quick3d | vips | Total |
|---|---|---|---|---|---|
| `CXMLNode` | 7 | 23 | 85 | 6 | ~121 |
| `CLogger` | 0 | 0 | 61 | 0 | 61 |
| `QTree` | 0 | 1 | 0 | ~70 via alias | ~71 |
| `CFactory` | 0 | 0 | 0 | ~18 | ~18 |
| `CSingleton` | 0 | 0 | 12 | 2 | 14 |
| `CFastList` | ~11 | 0 | 0 | 0 | ~11 |
| `CInterpolator` | 0 | 0 | 8 | 0 | 8 |
| `CDumpable` | 0 | 0 | 5+ heirs | 0 | ~5 |
| `CAverager` | 0 | 0 | 4 | 0 | 4 |
| `CPIDController` | 0 | 0 | 2 | 0 | 2 |
| `CLazyPointer` | 0 | 1 | 0 | 0 | 1 |
| `CTextGenerator` | 0 | tests only | 0 | 0 | tests only |
| `CRollingFiles` | 0 | 0 | 0 | 0 | 0 |
| `CTimeSampler` | 0 | 0 | 3 dead includes | 0 | 0 real |
| `CTracableMutex` | 0 | 0 | 0 | 0 | 0 |
| `CRollingAverager` | 0 | 0 | 0 | 0 | 0 |

## Hotspots

- `CXMLNode` is the serialization pivot of 3 repos out of 4: `toNode()`/`fromNode()`
  pattern all over `aze` (commits, branches, stash, network), `loadParameters(CXMLNode)`
  in ~85 `quick3d` files (every component loads its config this way), graph
  load/save in `vips`. Heaviest-used methods: `load()`, `parseXML()`,
  `parseJSON()`, `getNodeByTagName()`, `saveXMLToFile()`.
- `CLogger` is used in 61 `quick3d` files via the `LOG_*` macros.
- `QTree` carries data pin-to-pin in `vips` (`QVariantExtTree` alias, ~70 files,
  mostly `value()`/`setValue()`), plus a manual parent-chain walk in
  `ForEachNode.cpp` (a hand-rolled `path()`).
- `CFactory` is the central node factory of `vips` (`VipsFactory`,
  `registerProduct`/`instanciateProduct`/`CFactoryProductEnumerator`).
- `CSingleton` backs ~12 singletons in `quick3d` (`getInstance()` everywhere).
- `CInterpolator` drives flight/terrain curves in `quick3d` (`addValue`/`getValue`).
- `CPIDController` runs the `quick3d` drone control loop (`setSetPoint`/`update`/`output`).
- `CAverager` feeds the `quick3d` FPS display (`append`/`getAverage` hot path).
- `CFastList` holds the QML-exposed file list in `cutegit` (`CRepoFileList`).
- `CLazyPointer` holds lazy branch/commit pointers in `aze` (`CRepository`).
- `CDumpable` is the dump base of `quick3d` components/scenes (tests call `dump()`).
- `CRollingFiles`, `CTimeSampler`, `CTracableMutex`, `CRollingAverager` have no
  real callers in any of the 4 repos.
