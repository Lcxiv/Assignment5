#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H
#include"ListEmpty.h"
/*
Louis Condevaux
Section 1
C2305172
Assignment 4
DoublyLL.h
 */

/**
 * [ListNode is a class/structure used to store the nodes]
 */
#include <iostream>
using namespace std;

template <typename E> class ListNode{
public:
  E data;
  ListNode<E> *next;
  ListNode<E> *prev;

  ListNode();
  ListNode(E d);
  ~ListNode();
  //friend class DoublyLL;
};

/**
 * [ListNode default constructor]
 */

template<typename E>ListNode<E>::ListNode()
{
  next = nullptr;
  prev = nullptr;
}

/**
 * [ListNode Overloaded constructor]
 * @param d [description]
 */

template<typename E>ListNode<E>::ListNode(E d){
  next = nullptr;
  prev = nullptr;
  data = d;
}

/**
 * [~ListNode destructor]
 */

template<class E>ListNode<E>::~ListNode(){
  next = nullptr;
  prev = nullptr;
  delete next, prev;
};

/**
 * [DoublyLL header]
 */

template <class T> class DoublyLinkedList{
public:
  ListNode<T> *front;
  ListNode<T> *back;
  unsigned int size;

  DoublyLinkedList();
 ~DoublyLinkedList();

 //functions
 void insertFront(T d);
 void insertBack(T d);
 T removeFront();
 T removeBack();
 int deletePos(int pos);
 T find (int d);

 //helper Functions

bool isEmpty();
void printList();
T getFirst();
T getLast();
unsigned int getSize();
 //friend class Queue;
};

/**
 * [DoublyLinkedList default constructor]
 */

template<class T>
DoublyLinkedList<T>::DoublyLinkedList(){
  cout << "here in constructor" << endl;
  size = 0;
  front = NULL;
  back = NULL;
}

/**
 * [~DoublyLinkedList destructor]
 */

template<class T> DoublyLinkedList<T>::~DoublyLinkedList(){
  while(size > 0)
    {
      ListNode<T> *curr = front;
      if(size != 0)
      {
        front = front->next;
        front->prev = nullptr;
        curr->next = nullptr;
      }
      size--;
      delete curr;
    }
}

/**
 * [insertFront inserts at the beginning of the list]
 * @param d [description]
 */

 template<class T> void DoublyLinkedList<T>::insertFront(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if (size == 0)// empty ListNode
  {
    back = node;
  }else
  {
    //not empty list
    node->next = front;
    front->prev = node;
  }
  front = node;
  cout<<"node inserted at the front: "<<front->data<<endl;
  size++;
}

/**
 * [insertBack inserts at the end of the list]
 * @param d [description]
 */

template <class T> void DoublyLinkedList<T>::insertBack(T d)
{
  ListNode<T> *node = new ListNode<T>(d);
  if (size == 0)// empty ListNode
  {
    front = node;
  }else
  {
    //not empty list
    back->next = node;
    node->prev = back;
  }
  back = node;
  size++;
}

/**
 * [removeFront removies the first value of the list]
 */

template <class T> T DoublyLinkedList<T>::removeFront()
{
  if (size == 0)throw ListEmpty("The List is empty");
  ListNode<T> *ft = front; //temp pointer of the value to store it
  if (size == 1) //front ==back or fron->next == NULL
  {
    //it's the only node in the list
    back = NULL;
  }
  else
  {
    //we have more than one element in the list
    front->next->prev=NULL;
  }
  front = front->next;
  int tmp = front->data;
  ft->next=NULL;
  delete ft;
  size--;
  return tmp;
}

/**
 * [removeBack removes the last value of the list]
 */

template <class T>T DoublyLinkedList<T>::removeBack()
{
  ListNode<T> *temp = back;
  if (size == 0) cout<<"Empty, implement exception"<<endl;
  if (size == 1) back = front;
  else back->prev->next= NULL;
  back = back->prev;
  T *tmp = back->data;
  temp->prev = NULL;
  delete temp;
  size--;
  return tmp;
}

/**
 * [deletePos deletes an element at a specific position d]
 * @param d [description]
 */

template<class T> int DoublyLinkedList<T>::deletePos(int d)
{
  if(size==0) throw ListEmpty("The List is empty");
  ListNode<T> *curr = front;
  while (curr->data!=d)
  {
    curr = curr->next;
    if (curr== NULL)return 0; //changed it from NULL
  }
  if (curr==front) front = curr->next;
  else curr->prev->next = curr->next;
  if (curr==back) back = curr->prev;
  else curr->next->prev = curr->prev;
  int tmp = curr->data;
  curr->next= NULL;
  curr->prev = NULL;
  size--;
  return tmp;
}

/**
 * [printList prints the values inside the list]
 */

template <class T> void DoublyLinkedList<T>::printList()
{
  ListNode<T> *curr = front;
  while(curr != NULL || curr != nullptr)
    {
      //if (curr->next == NULL)break;
      cout<<curr->data<<endl;
      curr = curr->next;
    }
}

/**
 * [isEmpty returns true if the list is empty]
 */

template <class T> bool DoublyLinkedList<T>::isEmpty()
{
  return (size==0);
}

/**
 * [getSize returns the size of the list]
 */

template <class T> unsigned int DoublyLinkedList<T>::getSize()
{
  return size;
}

/**
 * [getFirst returns the first element of the list]
 */

template <class T> T DoublyLinkedList<T>::getFirst()
{
  return front->data;

}

/**
 * [getLast returns the last element of the list]
 */

template <class T> T DoublyLinkedList<T>::getLast()
{
  return back->data;
}

#endif
