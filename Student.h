/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
Student.h
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include"Person.h"

class Student : public Person
{
  int m_id;
  int m_advisorField;
  double m_studentGPA;
  std::string m_majorField;
  std::string m_name, m_level;

public:
  Student();
  Student(int id,std::string name, std::string level, std::string majorF, double GPAtotal, int advisorF);
  ~Student();

  int getID(){return m_id;};
  int getAdvisorField(){return m_advisorField;};
  void setAdvisor(int advisorID){m_advisorField = advisorID;};
  double getGPA(){return m_studentGPA;};
  std::string getName(){return m_name;};
  std::string getLevel(){return m_level;};
  std::string getMajorField(){return m_majorField;};

  //overloaded operators
  //https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/


  bool operator!= ( Student const &s1);
  bool operator== (Student  const &s1);
  bool operator> ( Student const &s1);
  bool operator>= ( Student const &s1);
  bool operator< ( Student const &s1);
  bool operator<= ( Student const &s1);


  void print();
};
#endif
