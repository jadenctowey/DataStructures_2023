#ifndef MONO_STACK_H
#define MONO_STACK_H

#include <iostream> //input/ output 

template <typename T>
class MonoStack{
    public: 
        MonoStack(int inputSize);
        virtual ~MonoStack();
        void push(T x);
        void printS();
        void pop();
        bool isEmpty();
        int size();
    private: 
        int top;    //top of stack
        int count;  //the number of items in stack
        int maxSize;    //the max options in stack 
        T* stackArr;
};

template <typename T>
MonoStack<T>:: MonoStack(int inputSize){        //set variables
    top = -1;
    count = 0;
    stackArr = new T[inputSize];
}

template <typename T>
MonoStack<T>:: ~MonoStack(){
    delete[] stackArr;          //deallocate 
}

template <typename T>
void MonoStack<T>::push(T x){
    if ((isEmpty() == true) || (x < stackArr[top])){
        stackArr[++top] = x;    //take one off value 
        ++count;                //add to count
        return;
    } else if (x > stackArr[top]){
        while ((isEmpty()!= true)&&(x > stackArr[top])) {
            pop();      //if it is not empty pop it off
        }
        stackArr[++top] = x;        //after run through it then top -1
        ++count;                //add to count 
        return;
    } 
}

template <typename T>
void MonoStack<T>::printS(){
    for (int i=0; i<=top; i++){         //iterate through the stack
        std::cout<<stackArr[i]<<',';
    }
    std::cout<<"\n";
}

template <typename T>
void MonoStack<T>::pop(){
    --top;              //takes one of the count and top for removing
    --count;
}

template <typename T>
bool MonoStack<T>::isEmpty(){
    return (count == 0);        //true false based on empty 
}

template <typename T>
int MonoStack<T>::size(){
    return count;           //final count 
}
#endif