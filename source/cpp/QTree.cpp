
// Application
#include "QTree.h"

/*!
    \class QTree
    \inmodule unis-lib
    \brief A template class for storing a tree, or a list, or a scalar.
*/

/*!
    \fn QTree::QTree()

    Constructs a QTree using default values.
*/

/*!
    \fn QTree::QTree(T value, QTree<T>* parent)

    Constructs a QTree and sets its value to \a value and its parent to \a parent.
*/

/*!
    \fn QTree::QTree(const QTree<T>& target)

    Constructs a copy of \a target.
*/

/*!
    \fn QTree::~QTree()

    Destroys a QTree.
*/

/*!
    \fn void QTree::setValue(T value)

    Sets the value of this tree node to \a value.
*/

/*!
    \fn int QTree::count() const

    Returns the number of child items in this tree node.
*/

/*!
    \fn void QTree::clear()

    Clears all child items of this tree node.
*/

/*!
    \fn int QTree::recursiveCount() const

    Returns the number of nodes in the whole tree, excluding this node.
*/

/*!
    \fn T& QTree::value()

    Returns the value of this tree node.
*/

/*!
    \fn const T& QTree::value() const

    Returns the value of this tree node.
*/

/*!
    \fn QTree<T>* QTree::parent() const

    Returns the parent node of this tree node. Can be \c {NULL}.
*/

/*!
    \fn QVector<QTree<T> >& QTree::getChildren()

    Returns a reference to a vector containing the child nodes of this tree node.
*/

/*!
    \fn const QVector<QTree<T> >& QTree::getChildren() const

    Returns a constant reference to a vector containing the child nodes of this tree node.
*/

/*!
    \fn QTree<T>* QTree::nodeForValue(const T& value)

    Returns the node that contains \a value. Searches recursively.
*/

/*!
    \fn QTree<T>* QTree::root() const

    Returns the root of the tree.
*/

/*!
    \fn QVector<T> QTree::flatValues() const

    Returns all values of the tree as a flat list.
*/

/*!
    \fn void QTree::append(T value)

    Appends \a value to the children of this tree node.
*/

/*!
    \fn void QTree::append(QTree<T> node)

    Appends \a node to the children of this tree node.
*/

/*!
    \fn void QTree::append(QTree<T>* node)

    Appends \a node to the children of this tree node.
*/

/*!
    \fn void QTree::removeAt(int n)

    Removes the child at position \a n in this tree node.
*/

/*!
    \fn void QTree::removeAll(const T& value)

    Removes \a value from the children of this node.
*/

/*!
    \fn void QTree::removeAll(const QTree<T>* node)

    Removes \a node from the children of this node.
*/

/*!
    \fn void moveNode(QTree<T>* nodeToMove, QTree<T>* newParentNode)

    Moves \a nodeToMove in \a newParentNode.
*/

/*!
    \fn bool QTree::contains(T value) const

    Returns \c true if one of this node's children is set to \a value.
*/

/*!
    \fn bool QTree::operator == (const QTree<T>& target) const

    Returns \c true if the value of this node is equal to the value of \a target.
*/

/*!
    \fn bool QTree::operator != (const QTree<T>& target) const

    Returns \c true if the value of this node is not equal to the value of \a target.
*/

/*!
    \fn QTree<T>& QTree::operator << (T value)

    Shortcut to the append() method, using the \a value.
*/

/*!
    \fn QTree<T>& QTree::operator << (QTree<T> value)

    Shortcut to the append() method, using the \a value.
*/

/*!
    \fn T& QTree::operator [] (int index)

    Returns the value of the child node at \a index.
*/

/*!
    \fn int position() const

    Returns the index of this node.
*/

/*!
    \fn QString path(const QString& sep = "/") const

    Returns the path to this node using \a sep as a separator.
*/
