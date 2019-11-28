/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
GenStack.h
 */
#ifndef _GENSTACK_H
#define _GENSTACK_H

#include "StackEmpty.h"
#include "StackFull.h"
#include <iostream>
using namespace std;
/**
 * [GenStack Template class used to create a stack, contains the header and the cpp file]
 */
template <typename E>

class GenStack {

public:
GenStack();
GenStack(int maxSize);
//GenStack (const E copy);
~GenStack();
void copyArray();
int getSize() const;
bool isEmpty() const;
//{return (top<0);};
bool isFull() const;
//{return (top == size-1);};
const E& peek () const throw(StackEmpty);
void push (const E& e) throw(StackFull);
void pop() throw (StackEmpty);

int size;
int top;
int capacity;
E* myArr;
};

/**
 * [GenStack Default constructor]
 */
template <typename E> GenStack<E>::GenStack(){
}

/**
 * [GenStack Overloaded constructor]
 * @param maxSize [int]
 */
template <typename E> GenStack<E>::GenStack(int maxSize)
{
        size = maxSize;
        top = -1;
        myArr = new E[maxSize];
}
// template <typename E> GenStack<E>::GenStack(const E copy)
// {
//   size = size *2;
//   E* tempArray = new E[size];
//   //for (auto& tempArray:myArr) tempArray[i] = myArr[i];
//   for (int i = 0; i<=top; i++) tempArray[i] = myArr[i];
//   ~GenStack();
//   for (int i = 0; i<=top; i++) myArr[i] = tempArray[i];
//   //myArr = tempArray;
// }

/**
 * [copyArray Copy Constructor, restructure the array to double the size]
 */
template <typename E> void GenStack<E>::copyArray()
{
        size = size *2;
        E* tempArray = new E[size];
        //for (auto& tempArray:myArr) tempArray[i] = myArr[i];
        for (int i = 0; i<=top; i++) tempArray[i] = myArr[i];
        delete[]myArr;
        //for (int i = 0; i<=top; i++) myArr[i] = tempArray[i];
        myArr = tempArray;
}
/**
 * [GenStack destructor]
 */
template <typename E> GenStack<E>::~GenStack()
{
        delete[]myArr;
}
/**
 * [getSize Returns the size of the array]
 */
template <typename E> int GenStack<E>::getSize() const
{
        return size;
}
/**
 * [isEmpty returns true if empty]
 */
template <typename E> bool GenStack<E>::isEmpty() const
{
        return (top < 0);
}
/**
 * [isFull returns true if false]
 */
template <typename E> bool GenStack<E>::isFull() const
{
        return (top == size-1);
}
/**
 * [Peek shows the first element of the stack]
 * @param  StackEmpty [Exception thrown if the stack is empty]
 * @return            [Object E]
 */
template <typename E> const E& GenStack<E>::peek() const throw(StackEmpty)
{
        if (isEmpty()) throw StackEmpty("Top of Empty stack");

        return myArr[top];
}
/**
 * [pop gets rid off the value on top of the stack and throws an exception if the stack is empty]
 */
template <typename E> void GenStack<E>::pop() throw (StackEmpty)
{
        if(isEmpty()) throw StackEmpty("Pop from Empty stack.");
        --top;
        //return myArr[top+1];

}

/**
 * [push inserts the value on top of the stack]
 * @param e [Object]
 */
template <typename E> void GenStack<E>::push(const E& e) throw(StackFull)
{
        if (isFull()) //throw StackFull("Full: Doubling the size of the stack.")
        {
                copyArray();
        }
        myArr[++top]= e;
};
#endif
