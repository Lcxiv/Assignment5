#ifndef MASTERSTUDENT_H
#define MASTERSTUDENT_H

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

  void print();


  friend class Menu;

};

#endif
