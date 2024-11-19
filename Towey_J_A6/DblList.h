//TOOK FROM NOTES 

#ifndef DBL_LIST_H
#define DBL_LIST_H
#include <cstdlib>

#include "ListNode.h"

template <typename T>
class DblList{
    public:
        DblList();
        virtual ~DblList();
        int size();
        bool isEmpty();
        void addFront(T data);
        void addBack(T data);
        void add(int pos, T data);
        T get(int pos);
        T removeFront();
        T removeBack();
        T remove(int pos);

    //private:                      //was getting errors while these were private so made public 
        ListNode<T>* m_front;
        ListNode<T>* m_back;
        int m_size;
};

template<typename T>
DblList<T>::DblList(){
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
DblList<T>::~DblList(){
    //todo - free memory - loop through and delete
    m_front = NULL;
    m_back = NULL;
    m_size = 0;
}

template<typename T>
int DblList<T>::size(){
    return m_size;
}

template<typename T>
bool DblList<T>::isEmpty(){
    return (m_size == 0);
}

template <typename T>
void DblList<T>::addFront(T data){
    ListNode<T>* newNode = new ListNode<T>(data); // create new node (aka newNode)
		// set newNode’s prev pointer to NULL (done in constructor)
    if (!isEmpty()){ // if linked list is not empty 
        newNode -> m_next = m_front; // set newNode’s next pointer to the old front (aka oldFront)
        m_front -> m_prev = newNode; // set oldFront’s prev pointer to newNode 
    } else { // if list is empty (newNode is 1st node) 
        m_back = newNode; // then set back to newNode too
    }
    m_front = newNode; // set front to newNode regardless 
    ++m_size; // add one to size 
}

template<typename T>
void DblList<T>::addBack(T data){
    ListNode<T>* newNode = new ListNode<T>(data);
    if(!isEmpty()){
        newNode->m_prev = m_back;
        m_back->m_next = newNode;
    }else{
        m_front = newNode;
    }
    m_back = newNode;
    ++m_size;
}

template<typename T>
void DblList<T>::add(int pos, T data){          //adding data at a certain position 
    if(isEmpty()){                              //if a position is empty 
        addFront(data);                         //then just add to front or back and it would not matter
    }else if(pos == 0){                         //0 means only trying to add to front so then just do that 
        addFront(data);
    }else if(pos >= m_size){                    //if it is greater than the size at all it is going to go to the back so just add there
        addBack(data);
    }else{
        ListNode<T>* current = m_front;         //if it is none of the above cases then start to iterate through 
        int cPos = 0;                           //current pos is going to be 0
        while(cPos != pos){                     // while it is not the position you want then keep going down the chain 
            current = current->m_next; 
            ++cPos;                             //add to pos variable if u are not there yet 
        }
        ListNode<T>* newNode = new ListNode<T>(data);       //create new node
        current->m_prev->m_next = newNode;                  //currents (D) previous pointer node (C) is going to change to new node (F)
        newNode->m_prev = current->m_prev;                  //new node (F) previous node will become the current (D) previous (C)
        current->m_prev = newNode;                          //now the currents (D) previous is set to (F) and that is the new node 
        newNode->m_next = current;                          //the new node (F) next is now set to current one were on (D)
        ++m_size;                                           //add 1 to whole size 
                                            //STARED A B C D E -> BECAME A B C F D E
    }
}

template<typename T>
T DblList<T>::removeFront(){
    //make sure not empty
    T data = m_front->m_data; //save data at old front so we can return later
    if(m_size == 1){
        delete m_front;
        m_front = NULL;
        m_back = NULL;
    }else{
        ListNode<T>* currFront = m_front; 
        m_front = m_front->m_next; //change the front to the next item in list because it is getting deleted 
        m_front->m_prev = NULL;     //the last pointer that was pointing to the one you just deleted needs to go too 
        delete currFront;
    }
    --m_size;
    return data;
}

template<typename T>
T DblList<T>::removeBack(){
    //make sure not empty
     T data = m_back->m_data;
     if(m_size == 1){
        delete m_back;
        m_front = NULL;
        m_back = NULL;
     }else{
        ListNode<T>* currBack = m_back;
        m_back = m_back->m_prev;
        m_back->m_next = NULL;
        delete currBack;
     }
     --m_size;
     return data;
}

template<typename T>
T DblList<T>::remove(int pos){
    //make sure not empty
    T data;
    if(pos == 0){               //when it is 0 that just gets rid of front
        data = removeFront();
    }else if(pos >= m_size -1){   //if it is greater than the list size or equal (-1) then remove the back
        data = removeBack();
    }else{
        ListNode<T>* current = m_front;         //set current to the node you want to remove
        int cPos = 0;
        while(cPos != pos){
            current = current->m_next;
            ++cPos;
        }
        data = current->m_data;                 //variable is the one we are getting rid of 
        current->m_prev->m_next = current->m_next;      //set the pointer of the previous one to the next one of current u are on
        current->m_next->m_prev = current->m_prev;      //set the pointer of the next one to the previous one of current u are on
        delete current;                                 //take urs out
        --m_size;                                       //subtract from total size
    }
    return data;
}

template<typename T>            //same logic to add and remove at certain spots!
T DblList<T>::get(int pos){
    //is pos in range, etc.
    ListNode<T>* current = m_front; //keep track of the current node you are at starting from the front 
    int cPos = 0;
    while(cPos != pos){   //keep iterating through the list if it does not equal the one that you want
        current = current->m_next;      //skip to next
        ++cPos;    //add one to current position bc we are 1 node further
    }
    return current->m_data; 
}


#endif