#ifndef BST_TEMPLATE_H
#define BST_TEMPLATE_H

#include<iostream>
using namespace std;

template <typename E> class TreeNode{
public:
  int key;
  E* data;
  TreeNode<E> *left;
  TreeNode<E> *right;

  TreeNode();
  TreeNode(int new_key, E* obj);
  ~TreeNode();
  TreeNode<E>* getLeft(){return left;};
  TreeNode<E>* getRight(){return right;};
  int getKey(){return key;};
  E* getData(){return data;};

};

template<typename E>TreeNode<E>::TreeNode()
{
  key = 0;
  data = nullptr;
  left = nullptr;
  right = nullptr;
}
template<typename E>TreeNode<E>::TreeNode(int new_key, E *obj)
{
  key = new_key;
  data = obj;
  left = nullptr;
  right = nullptr;
}

template<typename E>TreeNode<E>::~TreeNode()
{
  key = 0;
  data = nullptr;
  left = nullptr;
  right = nullptr;
  delete left, right, data;
}

template <class T> class BST{
  public:
  BST();
  ~BST();

  void Insert(TreeNode<T> *node);
  void DestroyTree(TreeNode<T>  *node);
  void InOrder(TreeNode<T>  *node);
  void PreOrder(TreeNode<T>  *node);
  void PostOrder(TreeNode<T>  *node);
  //void InsertAt(int value, TreeNode<T> *node);
  bool Search(int value);
  bool deleteNode(int value);
  TreeNode<T> * getSuccessor(TreeNode<T>  *d);

  //helper function
  bool isEmpty();
  TreeNode<T>* getMin(); //return pointer to the node
  TreeNode<T>* getMax(); //return pointer to the node
  void printTree();
  void recPrint(TreeNode<T> *node); //print a subtree if needed
  private:
    TreeNode<T> *root;
};

template <class T>BST<T>::BST(){
  root = nullptr; //empty tree
}

template <class T>BST<T>::~BST(){
  DestroyTree(root);
}

template<class T>void BST<T>::DestroyTree(TreeNode<T> *node)
{
  if (node != nullptr)
  {
    DestroyTree(node->left);
    DestroyTree(node->right);
    delete node;
  }
}

template <class T>void BST<T>::Insert(TreeNode<T> *node)
{
  if (root==NULL)
  {
    root = node;//if nothing in the tree, insert at root
    cout<<"Node inserted as the root."<<endl;
  }

  else
  {
    cout << "HERE "<< node->key << endl;
    TreeNode<T> *curr = root;
    TreeNode<T> *parent = nullptr;
    //had to get rid of a parentheses to make it local but doesn't stop the loop in main

  while(curr != NULL)//looping until the value is added somewhere on the tree
    {
      parent = curr;
      if(node->key < curr->key) //comparing to the root to know which direction to go
      {
        curr = curr->left; //defining the direction (left)

        if (curr == nullptr || curr == NULL)//we made it to the leafs
        {
            parent->left = node; //adding under the current/parent -> left since the value is smaller
            cout<<"node inserted"<<endl;
            break; //exiting the loop
        }
      }
      else
      {
        if (node->key > curr->key) //comparing to the root to know which direction to go
        {
          curr = curr->right; //defining the direction (right)
          if (curr == nullptr || curr == NULL) //we made it to the leafs
          {
            parent->right = node; //adding under the current/parent -> right since the value is greater
            cout<<"node inserted"<<endl;
            break; //exiting the loop
          }
        }
      }
    }
  }
}

template <class T> bool BST<T>::Search(int value)
{
  if (root == NULL || root->key == value)return false;
  else
  {
    TreeNode<T> *curr = root;
    while (curr->key != value)
    {
      if(value < curr->key)curr = curr->left;
      else curr = curr->right;
      if (curr == NULL)return false;
    }
  }
  return true;

}

template <class T> bool BST<T>::deleteNode(int value)
{
  if (root == NULL) return false;

  TreeNode<T> *curr = root;
  TreeNode<T> *parent = root;
  bool isLeft = true;

  //now let's look for the node to delete

  while (curr->key != value)
  {
    parent = curr;
    if(value < curr->key)
    {
      isLeft = true;
      curr = curr->left;
    }
    else
    {
      isLeft = false;
      curr = curr->right;
    }
    if (curr == NULL)return false;
  }
  //if we make it here, then we found the node that needs to be deleted
  //now let's check our different cases

  //no children
  if(curr->left == NULL && curr->right == NULL)//leaf with no children
  {
    if (curr==root) root = NULL;
    else if (isLeft) parent->left = NULL;
    else parent->right = NULL;
  }

  //node to be deleted has one child, we need to determine if child is left or right and proceed
  else if(curr->right == NULL) //has no right child
  {
    if(curr == root)
    {
      root = curr->left;
    }
    else if (isLeft)
    {
      parent->left = curr->left;
    }
    else
    {
      parent->right = curr->left;
    }
  }
  else if(curr->left == NULL) //has no left child
  {
    if(curr == root)
    {
      root = curr->right;
    }
    else if (isLeft)
    {
      parent->left = curr->right;
    }
    else
    {
      parent->right = curr->right;
    }
  }
  else//the node to delete has 2 children
  {
    TreeNode<T> *successor = getSuccessor(curr);
    if (curr == root)
    {
      root = successor;
    }
    else if (isLeft)
    {
      parent->left = successor;
    }
    else
    {
      parent->right = successor;
    }

    successor->left = curr->left;
  }
  cout<<"Object deleted"<<endl;
  return true;
}

template<class T> TreeNode<T>* BST<T>::getSuccessor(TreeNode<T> *d)//d is the node to be deleted
{
  TreeNode<T> *sp = d; //sp is successor's parent and is initialized to d
  TreeNode<T> *successor = d;
  TreeNode<T> *curr = d->right; //start one right
  while(curr!= NULL)
  {
    sp = successor;
    successor = curr;
    curr = curr->left;
  }
  if (successor != d->right) //successor is a descendant of the right child
  {
    sp->left = successor->right;
    successor->right = d->right;
  }
  return successor;
}

//helper functions

template <class T> void BST<T>::recPrint(TreeNode<T> *node)
{
  if (node == NULL) return;
  recPrint(node->left);
  cout<<node->key<<endl;
  recPrint(node->right);
}

template <class T> void BST<T>::InOrder(TreeNode<T> *node)
{
  if (node == NULL) return;
  recPrint(node->left);
  cout<<node->key<<endl;
  recPrint(node->right);
}

template <class T> void BST<T>::PostOrder(TreeNode<T> *node)
{
  if (node == NULL) return;
  recPrint(node->left);
  recPrint(node->right);
  cout<<node->key<<endl;
}

template <class T> void BST<T>::PreOrder(TreeNode<T> *node)
{
  if (node == NULL) return;
  cout<<node->key<<endl;
  recPrint(node->left);
  recPrint(node->right);
}

template <class T> void BST<T>::printTree()
{
  recPrint(root);
}

template <class T>
TreeNode<T>* BST<T>::getMax()
{
  TreeNode<T> *curr = root;
  if (curr == NULL)//empty tree
    return nullptr;

  while(curr->right != NULL)
  {
    curr = curr->right;
  }
}
template <class T>
TreeNode<T>* BST<T>::getMin()
{
  TreeNode<T> *curr = root;
  if (curr == NULL)//empty tree
    return curr;
  while(curr->left != NULL)
  {
    curr = curr->left;
  }
}
#endif
