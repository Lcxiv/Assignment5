#ifndef MASTERFACULTY_H
#define MASTERFACULTY_H

#include "BST_Template.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "FileReader.h"
#include<iostream>
using namespace std;

class masterFaculty
{
private:
  //TreeNode<Faculty> *nodeFaculty;
  BST<Faculty> *facultyTree = new BST<Faculty>();
  //Faculty *facultyStaff;

public:
  masterFaculty();
  ~masterFaculty();

  void addFaculty(TreeNode<Faculty> *node);
  void deleteFaculty(TreeNode<Faculty> *node);
  bool deleteAdvisee(int id);
  bool searchFaculty(int id);
  bool fileExists (const string &filename);
  void print();
  void printAdvisee();
  void readFromFile(string name);
  //void openFile(string name);
  void writeFile(string name, TreeNode<Faculty> *node);


};

#endif
