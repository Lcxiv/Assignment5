/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
masterStudent.h
 */

#ifndef MASTERSTUDENT_H
#define MASTERSTUDENT_H

#include "GenStack.h"
#include "BST_Template.h"
#include "Student.h"
#include "DoublyLinkedList.h"
#include "FileReader.h"
#include <iostream>
#include <fstream>

using namespace std;

class masterStudent
{
private:
  BST<Student> *studentTree = new BST<Student>();
  GenStack<BST<Student>*> *studentStack = new GenStack<BST<Student>*>(5);

public:

  masterStudent();
  ~masterStudent();

  void addStudent(TreeNode<Student> *node);
  void createStudent();
  void deleteStudent(unsigned int id);
  void findStudent(unsigned int id);
  bool Search(int idS);
  TreeNode<Student> *searchStudent(int idS);
  bool fileExists(const string &filename);
  void readFromFile(const string &name);
  void saveFile();
  void writeFile(const string &name, TreeNode<Student> *node);

  void addStack();
  void deleteStack();

  void print();


  friend class Menu;

};

#endif
