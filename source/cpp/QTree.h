
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QVector>

//-------------------------------------------------------------------------------------------------

//! This class defines a generic tree structure
template <class T>
class QTree
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Default constructor
    QTree()
        : m_Parent(nullptr)
    {
    }

    //! Constructor using value and parent
    QTree(T value, QTree<T>* parent = nullptr)
        : m_tValue(value)
        , m_Parent(parent)
    {
    }

    //! Copy constructor
    QTree(const QTree<T>& target)
        : m_tValue(target.m_tValue)
        , m_Parent(target.m_Parent)
        , m_vChildren(target.m_vChildren)
    {
    }

    //! Destructor
    virtual ~QTree()
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Sets this node's value
    void setValue(T value)
    {
        m_tValue = value;
    }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Returns this node's child count
    int count() const
    {
        return m_vChildren.count();
    }

    //! Resets the tree
    void clear()
    {
        m_vChildren.clear();
    }

    //! Returns this node's child count, descending through the whole tree
    int recursiveCount() const
    {
        return recursiveCount_internal(this);
    }

    //! Returns this node's value
    T& value()
    {
        return m_tValue;
    }

    //! Returns this node's value
    const T& value() const
    {
        return m_tValue;
    }

    //! Returns this node's parent
    QTree<T>* parent() const
    {
        return m_Parent;
    }

    //! Returns child nodes
    QList<QTree<T> >& getChildren()
    {
        return m_vChildren;
    }

    //! Returns child nodes
    const QList<QTree<T> >& getChildren() const
    {
        return m_vChildren;
    }

    //! Returns the node that contains the given value
    QTree<T>* nodeForValue(const T& value)
    {
        return nodeForValue_internal(this, value);
    }

    //! Returns the root node
    QTree<T>* root() const
    {
        const QTree<T>* pReturnValue = this;

        while (pReturnValue->m_Parent != nullptr)
        {
            pReturnValue = pReturnValue->m_Parent;
        }

        return const_cast<QTree<T>*>(pReturnValue);
    }

    //! Returns all values as a flat vector
    QVector<T> flatValues() const
    {
        QVector<T> lReturnValue;

        flatValues_Recurse(lReturnValue, root());

        return lReturnValue;
    }

    //-------------------------------------------------------------------------------------------------
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Appends a child value to this node
    void append(T value)
    {
        m_vChildren.append(QTree<T>(value, this));

        assignParents(root(), nullptr);
    }

    //! Appends a child node to this node
    void append(QTree<T> node)
    {
        m_vChildren.append(node);

        assignParents(root(), nullptr);
    }

    //! Appends a child node to this node
    void append(QTree<T>* node)
    {
        m_vChildren.append(*node);

        assignParents(root(), nullptr);
    }

    //! Deletes a child node by index
    void removeAt(int n)
    {
        m_vChildren.removeAt(n);
    }

    //! Removes all value in children
    void removeAll(const T& value)
    {
        for (int index = 0; index < m_vChildren.count(); index++)
        {
            if (m_vChildren[index].value() == value)
            {
                m_vChildren.removeAt(index);
                index--;
            }
        }
    }

    //! Removes all value in children
    void removeAll(const QTree<T>* node)
    {
        if (node != nullptr)
        {
            T value = node->value();

            for (int index = 0; index < m_vChildren.count(); index++)
            {
                if (m_vChildren[index].value() == value)
                {
                    m_vChildren.removeAt(index);
                    index--;
                }
            }
        }
    }

    //! Moves nodeToMove in newParentNode
    void moveNode(QTree<T>* nodeToMove, QTree<T>* newParentNode)
    {
        QTree<T>* pRoot = root();

        if (newParentNode == nullptr)
        {
            newParentNode = this;
        }

        if (nodeToMove != nullptr)
        {
            QTree<T>* currentParentNode = nodeToMove->parent();

            if (newParentNode != currentParentNode)
            {
                if (newParentNode != nullptr)
                {
                    newParentNode->append(nodeToMove);
                }

                if (currentParentNode != nullptr)
                {
                    currentParentNode->removeAll(nodeToMove);
                }
            }
        }

        assignParents(pRoot, nullptr);
    }

    //! Returns true if this node's chlidren contain the specified value
    bool contains(T value) const
    {
        for (QTree<T> node : m_vChildren)
        {
            bool bContains = node.contains(value);

            if (bContains)
            {
                return true;
            }
        }

        return false;
    }

    //! Returns true if both nodes values are equal
    bool operator == (const QTree<T>& target) const
    {
        return (m_tValue == target.m_tValue);
    }

    //! Returns true if both nodes values are not equal
    bool operator != (const QTree<T>& target) const
    {
        return !(*this == target);
    }

    //! Element appending operator
    QTree<T>& operator << (T value)
    {
        append(value);
        return *this;
    }

    //! Node appending operator
    QTree<T>& operator << (QTree<T> value)
    {
        append(value);
        return *this;
    }

    //! Indexer
    T& operator [] (int index)
    {
        return m_vChildren[index].value();
    }

    //! Index of
    int position() const
    {
        return m_Parent ? m_Parent->getChildren().indexOf(*this) : -1;
    }

    //-------------------------------------------------------------------------------------------------
    // Méthodes protégées
    // Protected methods
    //-------------------------------------------------------------------------------------------------

private:

    static int recursiveCount_internal(const QTree<T>* pTree)
    {
        int iResult = pTree->m_vChildren.count();

        for (int iIndex = 0; iIndex < pTree->m_vChildren.count(); iIndex++)
        {
            iResult += recursiveCount_internal(&(pTree->m_vChildren[iIndex]));
        }

        return iResult;
    }

    static QTree<T>* nodeForValue_internal(QTree<T>* pTree, const T& value)
    {
        if (pTree->m_tValue == value)
        {
            return pTree;
        }

        for (int index = 0; index < pTree->m_vChildren.count(); index++)
        {
            QTree<T>* pFound = nodeForValue_internal(&(pTree->m_vChildren[index]), value);

            if (pFound != nullptr)
            {
                return pFound;
            }
        }

        return nullptr;
    }

    static void assignParents(QTree<T>* pNode, QTree<T>* pParentNode)
    {
        pNode->m_Parent = pParentNode;

        for (int iIndex = 0; iIndex < pNode->m_vChildren.count(); iIndex++)
        {
            assignParents(&(pNode->m_vChildren[iIndex]), pNode);
        }
    }

    static void flatValues_Recurse(QVector<T>& list, const QTree<T>* pNode)
    {
        list.append(pNode->value());

        for (int iIndex = 0; iIndex < pNode->m_vChildren.count(); iIndex++)
        {
            flatValues_Recurse(list, &(pNode->m_vChildren[iIndex]));
        }
    }

    //-------------------------------------------------------------------------------------------------
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    T                   m_tValue;           // The node's value
    QTree<T>*           m_Parent;           // The parent of this node
    QList<QTree<T> >    m_vChildren;        // The children of this node
};

//-------------------------------------------------------------------------------------------------
