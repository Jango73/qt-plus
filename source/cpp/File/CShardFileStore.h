
#pragma once

#include "../qtplus_global.h"

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QMap>
#include <QObject>
#include <QSet>
#include <QString>
#include <QStringList>

// Library
#include "../CXMLNode.h"

//-------------------------------------------------------------------------------------------------

//! Persistent QString -> QStringList map split into lazily loaded shard files
//!
//! Keys are routed to a shard by longest hex-prefix match, so a single write
//! only rewrites the shard holding the key instead of the whole map. A shard
//! holding more than the split threshold is divided into 16 child shards
//! (next hex character), keeping per-write cost bounded as the map grows.
//! Each shard is persisted as a CXMLNode file through CXMLNode::load/save,
//! binary (.bin) by default or compressed XML (.xmlc) on request. Files are
//! named <base>.bin for the root shard and <base>-<prefix>.bin for the
//! others, so the routing table is rebuilt from a single folder listing and
//! no manifest file is required. Concurrent writers to the same shard are
//! unsupported by design (short-lived single-writer processes only).
class QTPLUSSHARED_EXPORT CShardFileStore : public QObject
{
    Q_OBJECT

public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructs a store rooted at sCacheFolder/sBaseName
    explicit CShardFileStore(
            const QString& sCacheFolder,
            const QString& sBaseName,
            QObject* pParent = nullptr,
            int iSplitThreshold = 2000,
            bool bUseBinary = true
            );

    //! Destructor, persists dirty shards
    virtual ~CShardFileStore() override;

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Returns true when an entry is stored for sKey (loads the shard on first use)
    bool containsValue(const QString& sKey) const;

    //! Returns the list stored for sKey, empty when missing (loads the shard on first use)
    QStringList value(const QString& sKey) const;

    //! Stores lValue for sKey, no-op when unchanged, splits the shard past the threshold
    void setValue(const QString& sKey, const QStringList& lValue);

    //! Drops the entry stored for sKey, if any
    void removeValue(const QString& sKey);

    //! Writes dirty shards, deletes orphaned parent files after splits
    void save();

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns the routing prefix holding sKey (longest known hex prefix, root when none matches)
    QString shardPrefixForKey(const QString& sKey) const;

    //! Returns the known routing prefixes (empty string is the root shard)
    QStringList knownPrefixes() const;

    //! Returns the number of known shards
    int shardCount() const;

    //! Returns the number of entries held in memory for sPrefix (loads the shard on first use)
    int shardEntryCount(const QString& sPrefix) const;

    //! Returns the file name backing sPrefix
    QString shardFileName(const QString& sPrefix) const;

protected:

    //-------------------------------------------------------------------------------------------------
    // Protected control methods
    //-------------------------------------------------------------------------------------------------

    //! Rebuilds the routing table from a single folder listing
    void buildRoutingTable();

    //! Loads sPrefix into memory on first access
    void ensureLoaded(const QString& sPrefix) const;

    //! Splits sPrefix into 16 child shards, marks children dirty, defers parent deletion to save()
    void splitShard(const QString& sPrefix);

    //! Serializes one shard to a node (entries as <entry key=...> holding <value> children)
    CXMLNode shardToNode(const QString& sPrefix, const QMap<QString, QStringList>& mEntries) const;

    //! Deserializes one shard node to entries
    QMap<QString, QStringList> shardFromNode(const CXMLNode& xNode) const;

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

    QString m_sCacheFolder;                                     // Folder holding the shard files
    QString m_sBaseName;                                        // Base file name without prefix or extension
    int m_iSplitThreshold;                                      // Entries per shard past which a split occurs
    bool m_bUseBinary;                                          // True for .bin files, false for .xmlc files

    QStringList m_lKnownPrefixes;                               // Routing table, longest match wins
    mutable QMap<QString, QMap<QString, QStringList>> m_mShardByPrefix; // Loaded entries by prefix
    mutable QSet<QString> m_sLoadedPrefixes;                    // Prefixes already loaded in memory
    QSet<QString> m_sDirtyPrefixes;                             // Loaded prefixes with unwritten changes
    QSet<QString> m_sRemovedPrefixes;                           // Split parents deleted from disk on save()
};
