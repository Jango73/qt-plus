
#pragma once

//-------------------------------------------------------------------------------------------------
// Includes

// Qt
#include <QVector>

//-------------------------------------------------------------------------------------------------

//! Cette classe définit un arbre générique
//! This class defines a generic tree structure
template <class T>
class QTree
{
public:

    //-------------------------------------------------------------------------------------------------
    // Constructeurs et destructeur
    // Constructors and destructor
    //-------------------------------------------------------------------------------------------------

    //! Constructeur par défaut
    //! Default constructor
    QTree()
        : m_Parent(NULL)
    {
    }

    //! Constructeur avec valeur et parent
    //! Constructor using value and parent
    QTree(T value, QTree<T>* parent = NULL)
        : m_tValue(value)
        , m_Parent(parent)
    {
    }

    //! Constructeur de copie
    //! Copy constructor
    QTree(const QTree<T>& target)
        : m_tValue(target.m_tValue)
        , m_Parent(target.m_Parent)
        , m_vChildren(target.m_vChildren)
    {
    }

    //! Destructeur
    //! Destructor
    virtual ~QTree()
    {
    }

    //-------------------------------------------------------------------------------------------------
    // Setters
    //-------------------------------------------------------------------------------------------------

    //! Définit la valeur de ce noeud
    //! Sets this node's value
    void setValue(T value)
    {
        m_tValue = value;
    }

    //-------------------------------------------------------------------------------------------------
    // Getters
    //-------------------------------------------------------------------------------------------------

    //! Retourne le nombre de noeuds enfants de ce noeud
    //! Returns this node's child count
    int count() const
    {
        return m_vChildren.count();
    }

    //! Remet l'arbre à zéro
    //! Resets the tree
    void clear()
    {
        m_vChildren.clear();
    }

    //! Retourne le nombre de noeuds enfants de ce noeud, en descendant dans l'arbre
    //! Returns this node's child count, descending through the whole tree
    int recursiveCount() const
    {
        return recursiveCount_internal(this);
    }

    //! Retourne la valeur de ce noeud
    //! Returns this node's value
    T& value()
    {
        return m_tValue;
    }

    //! Retourne la valeur de ce noeud
    //! Returns this node's value
    const T& value() const
    {
        return m_tValue;
    }

    //! Retourne le noeud parent de ce noeud
    //! Returns this node's parent
    QTree<T>* parent() const
    {
        return m_Parent;
    }

    //! Retourne les noeuds enfant
    //! Returns child nodes
    QList<QTree<T> >& getChildren()
    {
        return m_vChildren;
    }

    //! Retourne les noeuds enfant
    //! Returns child nodes
    const QList<QTree<T> >& getChildren() const
    {
        return m_vChildren;
    }

    //! Retourne le noeud qui contient la valeur spécifiée
    //! Returns the node that contains the given value
    QTree<T>* nodeForValue(const T& value)
    {
        return nodeForValue_internal(this, value);
    }

    QTree<T>* root() const
    {
        const QTree<T>* pReturnValue = this;

        while (pReturnValue->m_Parent != NULL)
        {
            pReturnValue = pReturnValue->m_Parent;
        }

        return const_cast<QTree<T>*>(pReturnValue);
    }

    QVector<T> flatValues() const
    {
        QVector<T> lReturnValue;

        flatflatValues_Recurse(lReturnValue, root());

        return lReturnValue;
    }

    //-------------------------------------------------------------------------------------------------
    // Méthodes de contrôle
    // Control methods
    //-------------------------------------------------------------------------------------------------

    //! Ajoute une valeur enfant à ce noeud
    //! Appends a child value to this node
    void append(T value)
    {
        m_vChildren.append(QTree<T>(value, this));

        assignParents(root(), NULL);
    }

    //! Ajoute un noeud enfant à ce noeud
    //! Appends a child node to this node
    void append(QTree<T> node)
    {
        m_vChildren.append(node);

        assignParents(root(), NULL);
    }

    //! Ajoute un noeud enfant à ce noeud
    //! Appends a child node to this node
    void append(QTree<T>* node)
    {
        m_vChildren.append(*node);

        assignParents(root(), NULL);
    }

    //! Supprime un noeud enfant par son indice
    //! Deletes a child node by index
    void removeAt(int n)
    {
        m_vChildren.removeAt(n);
    }

    //! Retire la valeur spécifiée des enfants
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

    //! Retire la valeur spécifiée des enfants
    //! Removes all value in children
    void removeAll(const QTree<T>* node)
    {
        if (node != NULL)
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

    //! Déplace nodeToMove dans newParentNode
    //! Moves nodeToMove in newParentNode
    void moveNode(QTree<T>* nodeToMove, QTree<T>* newParentNode)
    {
        QTree<T>* pRoot = root();

        if (newParentNode == NULL)
        {
            newParentNode = this;
        }

        if (nodeToMove != NULL)
        {
            QTree<T>* currentParentNode = nodeToMove->parent();

            if (newParentNode != currentParentNode)
            {
                if (newParentNode != NULL)
                {
                    newParentNode->append(nodeToMove);
                }

                if (currentParentNode != NULL)
                {
                    currentParentNode->removeAll(nodeToMove);
                }
            }
        }

        assignParents(pRoot, NULL);
    }

    //! Retourne vrai si les noeuds enfants contiennent la valeur spécifiée
    //! Returns true if this node's chlidren contain the specified value
    bool contains(T value) const
    {
        foreach (QTree<T> node, m_vChildren)
        {
            bool bContains = node.contains(value);

            if (bContains)
            {
                return true;
            }
        }

        return false;
    }

    //! Retourne vrai si la valeur de ce noeud est égale à la valeur du noeud spécifié
    //! Returns true if both nodes values are equal
    bool operator == (const QTree<T>& target) const
    {
        return (m_tValue == target.m_tValue);
    }

    //! Retourne vrai si la valeur de ce noeud n'est pas égale à la valeur du noeud spécifié
    //! Returns true if both nodes values are not equal
    bool operator != (const QTree<T>& target) const
    {
        return !(*this == target);
    }

    //! Opérateur d'ajout d'élément
    //! Element adding operator
    QTree<T>& operator << (T value)
    {
        append(value);
        return *this;
    }

    //! Opérateur d'ajout de noeud
    //! Node adding operator
    QTree<T>& operator << (QTree<T> value)
    {
        append(value);
        return *this;
    }

    //! Indexeur
    //! Indexer
    T& operator [] (int index)
    {
        return m_vChildren[index].value();
    }

    //! Index of
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

            if (pFound != NULL)
            {
                return pFound;
            }
        }

        return NULL;
    }

    static void assignParents(QTree<T>* pNode, QTree<T>* pParentNode)
    {
        pNode->m_Parent = pParentNode;

        for (int iIndex = 0; iIndex < pNode->m_vChildren.count(); iIndex++)
        {
            assignParents(&(pNode->m_vChildren[iIndex]), pNode);
        }
    }

    static void flatflatValues_Recurse(QVector<T>& list, const QTree<T>* pNode)
    {
        list.append(pNode->value());

        for (int iIndex = 0; iIndex < pNode->m_vChildren.count(); iIndex++)
        {
            flatflatValues_Recurse(list, &(pNode->m_vChildren[iIndex]));
        }
    }

    //-------------------------------------------------------------------------------------------------
    // Propriétés
    // Properties
    //-------------------------------------------------------------------------------------------------

protected:

    T                   m_tValue;           // La valeur de ce noeud
    QTree<T>*           m_Parent;           // Le noeud parent de ce noeud
    QList<QTree<T> >    m_vChildren;        // Les noeuds enfants de ce noeud
};

//-------------------------------------------------------------------------------------------------
