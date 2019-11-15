#ifndef FACULTY_H
#define FACULTY_H
#include "DoublyLinkedList.h"
#include <iostream>


class Faculty
{
  int facultyID, size;
  std::string name, level, department;
  DoublyLinkedList<int> *adviseeList= new DoublyLinkedList<int>(10);

public:
  Faculty();
  Faculty(int id, std::string n, std::string l, std::string d);
  ~Faculty();
  int getFacultyID(){return facultyID;};
  int getSize(){return size;}
  std::string getName(){return name;};
  std::string getLevel(){return level;};
  std::string getDepartment(){return department;};
  //DoublyLinkedList<int*> getAdviseeID(){return adviseeList;};

  int deleteStudent();
  void print();

};
#endif
