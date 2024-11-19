//took from previous stuff 

#ifndef TREENODE_H
#define TREENODE_H
 
#include <cstdlib>

template <typename T>
class TreeNode {
public:
    TreeNode(T data);           // data coming in 
    virtual ~TreeNode();        //would be for inheritance if in the future we want to add that but wont do that now
    T getData();
    template <typename S>       //this way we can access everything from tree node so that we can accesss everything 
    friend class BST;
    T m_data;
    TreeNode<T>* m_left;        //pointers but no seeters or getters for left and right 
    TreeNode<T>* m_right;
    int m_leftDepth;            //usually private but made public to work with lazy bst
    int m_rightDepth;
};

template <typename T>
TreeNode<T>::TreeNode(T data) {
    m_data = data;
    m_left = NULL;
    m_right = NULL;
    m_leftDepth = 0;
    m_rightDepth = 0;
}

template <typename T>
TreeNode<T>::~TreeNode() {
    if (m_left != NULL) {
        delete m_left;
    }
    if (m_right != NULL) {
        delete m_right;
    }
}

template <typename T>
T TreeNode<T>::getData() {
    return m_data;
}

#endif