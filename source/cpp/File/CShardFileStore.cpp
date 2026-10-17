
// Qt
#include <QDir>
#include <QFile>

// Library
#include "CShardFileStore.h"
#include "../CXMLNode.h"

//-------------------------------------------------------------------------------------------------

/*!
    \class CShardFileStore
    \inmodule qt-plus
    \brief Persistent QString to QStringList map split into lazily loaded shard files.
*/

// Shard node tags, kept local to the file format
static const char* s_sShardTag = "shard";
static const char* s_sEntryTag = "entry";
static const char* s_sValueTag = "value";
static const char* s_sKeyAttribute = "key";
static const char* s_sPrefixAttribute = "prefix";
static const char* s_sHexCharacters = "0123456789abcdef";
static const int s_iMaximumPrefixLength = 32;

//-------------------------------------------------------------------------------------------------

/*!
    Constructs a store rooted at \a sCacheFolder / \a sBaseName.
*/
CShardFileStore::CShardFileStore(
        const QString& sCacheFolder,
        const QString& sBaseName,
        QObject* pParent,
        int iSplitThreshold,
        bool bUseBinary
        )
    : QObject(pParent)
    , m_sCacheFolder(sCacheFolder)
    , m_sBaseName(sBaseName)
    , m_iSplitThreshold(iSplitThreshold)
    , m_bUseBinary(bUseBinary)
{
    if (m_iSplitThreshold < 1)
        m_iSplitThreshold = 1;

    buildRoutingTable();
}

//-------------------------------------------------------------------------------------------------

/*!
    Destroys a store, persisting dirty shards.
*/
CShardFileStore::~CShardFileStore()
{
    save();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns true when an entry is stored for \a sKey. \br
    The holding shard is loaded from disk on first access.
*/
bool CShardFileStore::containsValue(const QString& sKey) const
{
    if (sKey.isEmpty() || m_sBaseName.isEmpty())
        return false;

    QString sPrefix = shardPrefixForKey(sKey);
    ensureLoaded(sPrefix);

    return m_mShardByPrefix.value(sPrefix).contains(sKey);
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the list stored for \a sKey, empty when missing. \br
    The holding shard is loaded from disk on first access.
*/
QStringList CShardFileStore::value(const QString& sKey) const
{
    if (sKey.isEmpty() || m_sBaseName.isEmpty())
        return QStringList();

    QString sPrefix = shardPrefixForKey(sKey);
    ensureLoaded(sPrefix);

    return m_mShardByPrefix.value(sPrefix).value(sKey);
}

//-------------------------------------------------------------------------------------------------

/*!
    Stores \a lValue for \a sKey. \br
    No disk access happens beyond the holding shard file. A call with a value
    identical to the stored one is a no-op. A shard holding more than the
    split threshold is divided into 16 child shards on the next hex character.
*/
void CShardFileStore::setValue(const QString& sKey, const QStringList& lValue)
{
    if (sKey.isEmpty() || m_sBaseName.isEmpty())
        return;

    QString sPrefix = shardPrefixForKey(sKey);
    ensureLoaded(sPrefix);

    if (m_mShardByPrefix[sPrefix].contains(sKey)
            && m_mShardByPrefix[sPrefix].value(sKey) == lValue)
        return;

    m_mShardByPrefix[sPrefix][sKey] = lValue;
    m_sDirtyPrefixes.insert(sPrefix);
    m_sRemovedPrefixes.remove(sPrefix);

    if (m_mShardByPrefix[sPrefix].count() > m_iSplitThreshold
            && sPrefix.length() < s_iMaximumPrefixLength)
    {
        splitShard(sPrefix);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Drops the entry stored for \a sKey, if any. \br
    The holding shard is marked dirty only when an entry was removed.
*/
void CShardFileStore::removeValue(const QString& sKey)
{
    if (sKey.isEmpty() || m_sBaseName.isEmpty())
        return;

    QString sPrefix = shardPrefixForKey(sKey);
    ensureLoaded(sPrefix);

    if (m_mShardByPrefix[sPrefix].remove(sKey) > 0)
    {
        m_sDirtyPrefixes.insert(sPrefix);
        m_sRemovedPrefixes.remove(sPrefix);
    }
}

//-------------------------------------------------------------------------------------------------

/*!
    Writes dirty shards, deletes orphaned parent files after splits.
*/
void CShardFileStore::save()
{
    if (m_sBaseName.isEmpty())
        return;

    if (m_sDirtyPrefixes.isEmpty() && m_sRemovedPrefixes.isEmpty())
        return;

    if (m_sCacheFolder.isEmpty())
        return;

    QDir().mkpath(m_sCacheFolder);

    for (const QString& sPrefix : m_sDirtyPrefixes)
    {
        if (not m_mShardByPrefix.contains(sPrefix))
            continue;

        CXMLNode xNode = shardToNode(sPrefix, m_mShardByPrefix.value(sPrefix));
        xNode.save(shardFileName(sPrefix));
    }

    m_sDirtyPrefixes.clear();

    for (const QString& sPrefix : m_sRemovedPrefixes)
    {
        // The parent file is written with the active extension, still remove
        // the alternate one so a format switch leaves no stale shard behind
        QString sBinaryName = m_sCacheFolder + "/" + m_sBaseName
                + (sPrefix.isEmpty() ? "" : "-" + sPrefix) + CXMLNode::sExtension_BIN;
        QString sTextName = m_sCacheFolder + "/" + m_sBaseName
                + (sPrefix.isEmpty() ? "" : "-" + sPrefix) + CXMLNode::sExtension_XMLC;

        QFile::remove(sBinaryName);
        QFile::remove(sTextName);
    }

    m_sRemovedPrefixes.clear();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the routing prefix holding \a sKey. \br
    The longest known hex prefix matching the lowercased key wins. Keys with
    no hex match (or an empty routing table) fall back to the root shard.
*/
QString CShardFileStore::shardPrefixForKey(const QString& sKey) const
{
    QString sLowerKey = sKey.toLower();
    QString sBestMatch;

    for (const QString& sPrefix : m_lKnownPrefixes)
    {
        if (sPrefix.isEmpty())
            continue;

        if (sLowerKey.startsWith(sPrefix) && sPrefix.length() > sBestMatch.length())
            sBestMatch = sPrefix;
    }

    return sBestMatch;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the known routing prefixes.
*/
QStringList CShardFileStore::knownPrefixes() const
{
    return m_lKnownPrefixes;
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of known shards.
*/
int CShardFileStore::shardCount() const
{
    return m_lKnownPrefixes.count();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the number of entries held in memory for \a sPrefix. \br
    The shard is loaded from disk on first access.
*/
int CShardFileStore::shardEntryCount(const QString& sPrefix) const
{
    ensureLoaded(sPrefix);

    return m_mShardByPrefix.value(sPrefix).count();
}

//-------------------------------------------------------------------------------------------------

/*!
    Returns the file name backing \a sPrefix.
*/
QString CShardFileStore::shardFileName(const QString& sPrefix) const
{
    QString sExtension = m_bUseBinary ? CXMLNode::sExtension_BIN : CXMLNode::sExtension_XMLC;

    if (sPrefix.isEmpty())
        return m_sCacheFolder + "/" + m_sBaseName + sExtension;

    return m_sCacheFolder + "/" + m_sBaseName + "-" + sPrefix.toLower() + sExtension;
}

//-------------------------------------------------------------------------------------------------

/*!
    Rebuilds the routing table from a single folder listing. \br
    File names are parsed back to prefixes, so no manifest file is required.
    An empty or missing folder yields the single root shard.
*/
void CShardFileStore::buildRoutingTable()
{
    m_lKnownPrefixes.clear();

    if (m_sBaseName.isEmpty() || m_sCacheFolder.isEmpty())
    {
        m_lKnownPrefixes << "";
        return;
    }

    QDir tFolder(m_sCacheFolder);

    if (not tFolder.exists())
    {
        m_lKnownPrefixes << "";
        return;
    }

    QStringList lFiles = tFolder.entryList(QDir::Files);

    for (const QString& sFile : lFiles)
    {
        if (not sFile.startsWith(m_sBaseName))
            continue;

        QString sRemainder = sFile.mid(m_sBaseName.length());

        if (sRemainder.endsWith(CXMLNode::sExtension_BIN))
        {
            sRemainder.chop(int(strlen(CXMLNode::sExtension_BIN)));
        }
        else if (sRemainder.endsWith(CXMLNode::sExtension_XMLC))
        {
            sRemainder.chop(int(strlen(CXMLNode::sExtension_XMLC)));
        }
        else
        {
            continue;
        }

        QString sPrefix;

        if (sRemainder.isEmpty())
        {
            sPrefix = "";
        }
        else
        {
            if (not sRemainder.startsWith("-"))
                continue;

            sPrefix = sRemainder.mid(1).toLower();
        }

        bool bIsHex = true;

        for (const QChar& tCharacter : sPrefix)
        {
            if (not QString(s_sHexCharacters).contains(tCharacter))
            {
                bIsHex = false;
                break;
            }
        }

        if (bIsHex && not m_lKnownPrefixes.contains(sPrefix))
            m_lKnownPrefixes << sPrefix;
    }

    if (m_lKnownPrefixes.isEmpty())
        m_lKnownPrefixes << "";
}

//-------------------------------------------------------------------------------------------------

/*!
    Loads \a sPrefix into memory on first access. \br
    A missing shard file yields an empty shard without error.
*/
void CShardFileStore::ensureLoaded(const QString& sPrefix) const
{
    if (m_sLoadedPrefixes.contains(sPrefix))
        return;

    m_sLoadedPrefixes.insert(sPrefix);

    if (not m_mShardByPrefix.contains(sPrefix))
        m_mShardByPrefix[sPrefix] = QMap<QString, QStringList>();

    QString sFileName = shardFileName(sPrefix);

    if (not QFile::exists(sFileName))
        return;

    CShardFileStore* pThis = const_cast<CShardFileStore*>(this);
    pThis->m_mShardByPrefix[sPrefix] = shardFromNode(CXMLNode::load(sFileName));
}

//-------------------------------------------------------------------------------------------------

/*!
    Splits \a sPrefix into 16 child shards on the next hex character. \br
    Entries are redistributed by the lowercased character at the split
    position, non-hex or short keys falling into the "0" child. All 16
    children are materialized so routing needs no manifest file. The parent
    file is deleted on the next save(), after the children are written.
*/
void CShardFileStore::splitShard(const QString& sPrefix)
{
    QMap<QString, QStringList> mEntries = m_mShardByPrefix.value(sPrefix);

    m_mShardByPrefix.remove(sPrefix);
    m_sDirtyPrefixes.remove(sPrefix);
    m_lKnownPrefixes.removeAll(sPrefix);

    for (const QChar& tCharacter : QString(s_sHexCharacters))
    {
        QString sChild = sPrefix + tCharacter;

        if (not m_lKnownPrefixes.contains(sChild))
            m_lKnownPrefixes << sChild;

        if (not m_mShardByPrefix.contains(sChild))
        {
            m_mShardByPrefix[sChild] = QMap<QString, QStringList>();
            m_sLoadedPrefixes.insert(sChild);
        }

        m_sDirtyPrefixes.insert(sChild);
    }

    for (auto iEntry = mEntries.constBegin(); iEntry != mEntries.constEnd(); iEntry++)
    {
        QString sLowerKey = iEntry.key().toLower();
        QChar tSplitCharacter = QChar('0');

        if (sPrefix.length() < sLowerKey.length())
        {
            QChar tCandidate = sLowerKey[sPrefix.length()];

            if (QString(s_sHexCharacters).contains(tCandidate))
                tSplitCharacter = tCandidate;
        }

        m_mShardByPrefix[sPrefix + tSplitCharacter][iEntry.key()] = iEntry.value();
    }

    m_sRemovedPrefixes.insert(sPrefix);
}

//-------------------------------------------------------------------------------------------------

/*!
    Serializes one shard to a node. \br
    Each entry is an <entry key="..."> node holding one <value> child per
    list item, so keys and values never collide with separators.
*/
CXMLNode CShardFileStore::shardToNode(const QString& sPrefix, const QMap<QString, QStringList>& mEntries) const
{
    CXMLNode xRoot(s_sShardTag);
    xRoot.attributes()[s_sPrefixAttribute] = sPrefix;

    for (const QString& sKey : mEntries.keys())
    {
        CXMLNode xEntry(s_sEntryTag);
        xEntry.attributes()[s_sKeyAttribute] = sKey;

        for (const QString& sItem : mEntries.value(sKey))
        {
            CXMLNode xValue(s_sValueTag);
            xValue.setValue(sItem);
            xEntry << xValue;
        }

        xRoot << xEntry;
    }

    return xRoot;
}

//-------------------------------------------------------------------------------------------------

/*!
    Deserializes one shard node to entries. \br
    Unknown child tags are skipped, entries without key are dropped.
*/
QMap<QString, QStringList> CShardFileStore::shardFromNode(const CXMLNode& xNode) const
{
    QMap<QString, QStringList> mReturnValue;

    for (const CXMLNode& xEntry : xNode.nodes())
    {
        if (xEntry.tag() != s_sEntryTag)
            continue;

        QString sKey = xEntry.attributes().value(s_sKeyAttribute);

        if (sKey.isEmpty())
            continue;

        QStringList lValue;

        for (const CXMLNode& xValue : xEntry.nodes())
        {
            if (xValue.tag() == s_sValueTag)
                lValue << xValue.value();
        }

        mReturnValue[sKey] = lValue;
    }

    return mReturnValue;
}
