#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include"Person.h"


class Student : public Person
{
  //int studentID;
  int m_advisorField;
  double m_studentGPA;
  std::string m_majorField;
  std::string m_name, m_level;
  int m_id;

public:
  //Student();
  Student(int id,std::string name, std::string level, std::string majorF, double GPAtotal, int advisorF);
  ~Student();

  int getID(){return m_id;};
  int getAdvisorField(){return m_advisorField;};
  double getGPA(){return m_studentGPA;};
  std::string getName(){return m_name;};
  std::string getLevel(){return m_level;};
  std::string getMajorField(){return m_majorField;};
  bool GreaterThan(int &comp1, int &comp2);
  bool compareSTR(std::string &a, std::string &b);
  void print();
};
#endif
