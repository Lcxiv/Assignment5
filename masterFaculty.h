#ifndef MASTERFACULTY_H
#define MASTERFACULTY_H

#include "BST_Template.h"
#include "Faculty.h"
#include "DoublyLinkedList.h"
#include "FileReader.h"
#include <iostream>
#include <fstream>
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
  void createFaculty();
  void deleteFaculty(int id);
  bool deleteAdvisee(int id);
  //Faculty* searchFaculty(int id);
  bool fileExists (const string &filename);
  void print();
  void printAdvisee();
  void readFromFile(string name);
  void saveFile();
  void writeFile(const string &name, TreeNode<Faculty>*node);
  void printFaculty(int id);
  
  friend class Menu;


};

#endif
