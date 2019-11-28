/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
masterFaculty.h
 */


#ifndef MASTERFACULTY_H
#define MASTERFACULTY_H

#include "BST_Template.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "FileReader.h"
#include "GenStack.h"
#include <iostream>
#include <fstream>

using namespace std;

class masterFaculty
{
private:

  //TreeNode<Faculty> *nodeFaculty;
  BST<Faculty> *facultyTree = new BST<Faculty>();
  GenStack<BST<Faculty>*> *facultyStack = new GenStack<BST<Faculty>*>(5);
  //Faculty *facultyStaff;

public:
  masterFaculty();
  ~masterFaculty();

  void addFaculty(TreeNode<Faculty> *node);
  void createFaculty();
  void deleteFaculty(int id);
  bool deleteAdvisee(int id);
  bool Search(int idF);
  TreeNode<Faculty> *searchFaculty(int idF);
  bool fileExists (const string &filename);
  void print();
  void printAdvisee();
  void readFromFile(const string &name);
  void writeFile(const string &name, TreeNode<Faculty>*node);
  void saveFile();
  void printFaculty(int id);

  void addStack();
  void deleteStack();

  friend class Menu;


};

#endif
