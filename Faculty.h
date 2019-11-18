#ifndef FACULTY_H
#define FACULTY_H
#include "DoublyLinkedList.h"
#include "Person.h"
#include <iostream>


class Faculty : public Person
{
private:
  int m_id;
  std::string m_name, m_level, m_department;
  DoublyLinkedList<int> *adviseeList;

public:
  Faculty();
  Faculty(int id, std::string name, std::string level, std::string department);
  ~Faculty();
  void addStudent(int studID);
  int removeStudent(int studID);
  int getID(){return m_id;};
  int getSize(){adviseeList->getSize();}
  std::string getName(){return m_name;};
  std::string getLevel(){return m_level;};
  std::string getDepartment(){return m_department;};
  //DoublyLinkedList<int*> getAdviseeID(){return adviseeList;};

  int deleteStudent();
  void print();
  void printAdvisee();

  bool operator!= (const Faculty &f1);
  bool operator== (const Faculty &f1);
  bool operator> (const Faculty &f1);
  bool operator>= (const Faculty &f1);
  bool operator< (const Faculty &f1);
  bool operator<= (const Faculty &f1);

};
#endif
