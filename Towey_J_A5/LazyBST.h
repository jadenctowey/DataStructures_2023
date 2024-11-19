#ifndef LAZYBST_H 
#define LAZYBST_H

#include "TreeNode.h"
#include <iostream>
#include <fstream>
#include <algorithm>
#include "Teacher.h"

using namespace std;

template <typename T>
class LazyBST{
    public:
        LazyBST();
        virtual ~LazyBST();
        int getSize();
        void insert(T data);
        void remove(T data);
        bool contains(T data);
        void printTreeInOrder();
        void printTreePostOrder();
        T getMin();
        T getMax();
        T findElement(const T& data);
        T findElementTeach(Teacher *teacher);
        void printTreeInOrderFile(ofstream& outputFile);
        void printTreeInOrderHelperFile(TreeNode<T>* subTreeRoot, ofstream& outputFile);
    
    private:
        TreeNode<T>* m_root;
        int m_size;
        void insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode);
        bool containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode);
        void printTreeInOrderHelper(TreeNode<T>* subTreeRoot);
        void printTreePostOrderHelper(TreeNode<T>* subTreeRoot);
        T getMinHelper(TreeNode<T>* subTreeRoot);
        T getMaxHelper(TreeNode<T>* subTreeRoot);
        void findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent);
        TreeNode<T>* getSuccessor(TreeNode<T>* rightChild);

        void updateDepths(TreeNode<T>* subTreeRoot);
        void rebalance(TreeNode<T>*& subTreeRoot);
        void countElements(TreeNode<T>* subTreeRoot, int& count);
        void storeElements(TreeNode<T>* subTreeRoot, T* elements, int& index);
        void buildBalancedTree(const T* elements, TreeNode<T>*& subTreeRoot, int start, int end);
};

template <typename T>
LazyBST<T>::LazyBST(){
    m_root = NULL;
    m_size = 0;
}

template <typename T>
LazyBST<T>::~LazyBST(){
}

template <typename T>
int LazyBST<T>::getSize(){
    return m_size;
}


template <typename T>
void LazyBST<T>::insert(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    insertHelper(m_root, newNode);
    ++m_size;
}

template <typename T>
void LazyBST<T>::insertHelper(TreeNode<T>*& subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        subTreeRoot = newNode; //pointer swap
    }else if(newNode->m_data < subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_left, newNode);
    }else if(newNode->m_data > subTreeRoot->m_data){
        insertHelper(subTreeRoot->m_right, newNode);
    }
    updateDepths(subTreeRoot);
    rebalance(subTreeRoot);
}


template <typename T>
void LazyBST<T>::updateDepths(TreeNode<T>* subTreeRoot) {
    if (subTreeRoot != nullptr) {
        int leftDepth = (subTreeRoot->m_left != nullptr) ? max(subTreeRoot->m_left->m_leftDepth, subTreeRoot->m_left->m_rightDepth) + 1 : 0;
        int rightDepth = (subTreeRoot->m_right != nullptr) ? max(subTreeRoot->m_right->m_leftDepth, subTreeRoot->m_right->m_rightDepth) + 1 : 0;

        subTreeRoot->m_leftDepth = leftDepth;
        subTreeRoot->m_rightDepth = rightDepth;

        updateDepths(subTreeRoot->m_left);
        updateDepths(subTreeRoot->m_right);
    }
}

template <typename T>
void LazyBST<T>::rebalance(TreeNode<T>*& subTreeRoot) {
    if (subTreeRoot == nullptr) {
        return;
    }

    int leftDepth = (subTreeRoot->m_left != nullptr) ? max(subTreeRoot->m_left->m_leftDepth, subTreeRoot->m_left->m_rightDepth) + 1 : 0;
    int rightDepth = (subTreeRoot->m_right != nullptr) ? max(subTreeRoot->m_right->m_leftDepth, subTreeRoot->m_right->m_rightDepth) + 1 : 0;

    int balanceFactor = leftDepth - rightDepth;

    if (abs(balanceFactor) > 1) {
        int elementCount = 0;
        countElements(subTreeRoot, elementCount);
        T* elements = new T[elementCount];
        int index = 0;
        storeElements(subTreeRoot, elements, index);
        subTreeRoot = nullptr;
        buildBalancedTree(elements, subTreeRoot, 0, elementCount - 1);
        delete[] elements;
        updateDepths(subTreeRoot);
    }
}

template <typename T>
void LazyBST<T>::countElements(TreeNode<T>* subTreeRoot, int& count) {
    if (subTreeRoot != nullptr) {
        countElements(subTreeRoot->m_left, count);
        ++count;
        countElements(subTreeRoot->m_right, count);
    }
}

template <typename T>
void LazyBST<T>::storeElements(TreeNode<T>* subTreeRoot, T* elements, int& index) {
    if (subTreeRoot != nullptr) {
        storeElements(subTreeRoot->m_left, elements, index);
        elements[index++] = subTreeRoot->m_data;
        storeElements(subTreeRoot->m_right, elements, index);
    }
}

template <typename T>
void LazyBST<T>::buildBalancedTree(const T* elements, TreeNode<T>*& subTreeRoot, int start, int end) {
    if (start > end) {
        return;
    }

    int mid = (start + end) / 2;
    subTreeRoot = new TreeNode<T>(elements[mid]);

    buildBalancedTree(elements, subTreeRoot->m_left, start, mid - 1);
    buildBalancedTree(elements, subTreeRoot->m_right, mid + 1, end);
}



template <typename T>
bool LazyBST<T>::contains(T data){
    TreeNode<T>* newNode = new TreeNode<T>(data);
    return containsHelper(m_root, newNode);
}

template <typename T>
bool LazyBST<T>::containsHelper(TreeNode<T>* subTreeRoot, TreeNode<T>* newNode){
    if(subTreeRoot == NULL){
        return false;
    }else if(newNode->m_data == subTreeRoot->m_data){
        return true;
    }else if(newNode->m_data < subTreeRoot->m_data){
        return containsHelper(subTreeRoot->m_left, newNode);
    }else{
        return containsHelper(subTreeRoot->m_right, newNode);
    }
}

template <typename T>
void LazyBST<T>::printTreeInOrder(){
    printTreeInOrderHelper(m_root);
}

template <typename T>
void LazyBST<T>::printTreeInOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreeInOrderHelper(subTreeRoot -> m_left);
        cout << subTreeRoot->m_data << endl;
        printTreeInOrderHelper(subTreeRoot -> m_right);
    }
}

template <typename T>
void LazyBST<T>::printTreeInOrderFile(ofstream& outputFile){
    printTreeInOrderHelperFile(m_root, outputFile);
}

template <typename T>
void LazyBST<T>::printTreeInOrderHelperFile(TreeNode<T>* subTreeRoot, ofstream& outputFile){
    if(subTreeRoot != NULL){
        printTreeInOrderHelperFile(subTreeRoot -> m_left, outputFile);
        outputFile << subTreeRoot->m_data << endl;
        printTreeInOrderHelperFile(subTreeRoot -> m_right, outputFile);
    }
}

template <typename T>
void LazyBST<T>::printTreePostOrder(){
    printTreePostOrderHelper(m_root);
}

template <typename T>
void LazyBST<T>::printTreePostOrderHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot != NULL){
        printTreePostOrderHelper(subTreeRoot->m_left);
        printTreePostOrderHelper(subTreeRoot->m_right);
        cout << subTreeRoot->m_data << endl;
    }
}

template <typename T>
T LazyBST<T>::getMin(){
    if(getSize() == 0){
        return -1;
    }
    return getMinHelper(m_root);
}

template <typename T>
T LazyBST<T>::getMinHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_left == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMinHelper(subTreeRoot->m_left);
    }
}

template <typename T>
T LazyBST<T>::getMax(){
    if(getSize() == 0){
        return T();
    }
    return getMaxHelper(m_root);
}

template <typename T>
T LazyBST<T>::getMaxHelper(TreeNode<T>* subTreeRoot){
    if(subTreeRoot->m_right == NULL){
        return subTreeRoot->m_data;
    }else{
        return getMaxHelper(subTreeRoot->m_right);
    }
}

template <typename T>
void LazyBST<T>::findTarget(T key, TreeNode<T>*& target, TreeNode<T>*& parent){
    while(target != NULL && target->m_data != key){
        parent = target;
        if(key < target->m_data){
            target = target->m_left;
        }else{
            target = target->m_right;
        }
    }

}

template <typename T>
TreeNode<T>* LazyBST<T>::getSuccessor(TreeNode<T>* rightChild){
    while(rightChild->m_left != NULL){
        rightChild = rightChild->m_left;
    }
    return rightChild;
}

template <typename T>
void LazyBST<T>::remove(T d){
    if(getSize() == 0){
        return;
    } 
    TreeNode<T>* target = NULL;
    TreeNode<T>* parent = NULL;
    target = m_root;
    findTarget(d,target, parent);
    if(target == NULL){ //not in the tree, nothing to do
        return;
    }
    if(target->m_left == NULL && target->m_right == NULL){ //no children, it's a leaf
        if(target == m_root){
            m_root = NULL;
        }else{ //it's not the root
            if(target == parent->m_left){
                parent->m_left = NULL;
            }else{
                parent->m_right = NULL;
            }
        }
        //delete target; //free the memory
    }else if(target->m_left != NULL && target->m_right !=NULL){ // 2 child case
        TreeNode<T>* suc = getSuccessor(target->m_right);
        T value = suc->m_data;
        remove(value);
        target->m_data = value;
    }else{ // 1 child case
        TreeNode<T>* child;
        if(target->m_left != NULL){
            child = target->m_left;
        }else{
            child = target->m_right;
        }
        if(target == m_root){
            m_root = child;
        }else{
            if(target == parent->m_left){
                parent->m_left = child;
            }else{
                parent->m_right = child;
            }
        }
        delete target; //free memory

    }
    --m_size;
}

template <typename T>
T LazyBST<T>::findElement(const T& data) {
    TreeNode<T>* currentNode = m_root;
    while (currentNode != nullptr) {
        if ((data == currentNode->m_data || currentNode->m_data == data)) {
            // Element found, return the element
            return currentNode->m_data;
        } else if (data < currentNode->m_data) {
            currentNode = currentNode->m_left;
        } else {
            currentNode = currentNode->m_right;
        }
    }

    // Element not found, return a default-constructed T
    return T();
}

template <>
Teacher* LazyBST<Teacher*>::findElementTeach(Teacher* teacher) {
    TreeNode<Teacher*>* currentNode = m_root;
    while (currentNode != nullptr) {
        if (currentNode->m_data->equals(teacher)) {
            // Element found, return the element
            return currentNode->m_data;
        } else if (teacher < currentNode->m_data) {
            currentNode = currentNode->m_left;
        } else {
            currentNode = currentNode->m_right;
        }
    }

    // Element not found, return a default-constructed Teacher*
    return nullptr;
}


#endif