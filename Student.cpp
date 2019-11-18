#include<iostream>
#include "Student.h"
#include "Person.h"


Student::Student(){}

Student::~Student(){}

Student::Student(int id,std::string name, std::string level, std::string majorF, double GPAtotal, int advisorF):
m_id(id),m_name(name), m_level(level), m_majorField(majorF), m_studentGPA(GPAtotal), m_advisorField(advisorF){};


//helper functions


void Student::print()
{
  std::cout<<"the Student's ID is: "<<getID()<<"\n";
  std::cout<<"the Student's advisor is: "<<getAdvisorField()<<"\n";
  std::cout<<"the Student's GPA is: "<<getGPA()<<"\n";
  std::cout<<"the Student's field is: "<<getName()<<"\n";
  std::cout<<"the Student's level is: "<<getLevel()<<"\n";
  std::cout<<"the Student's major is: "<<getMajorField()<<"\n";
}

//overloaded operators
//https://www.learncpp.com/cpp-tutorial/96-overloading-the-comparison-operators/


bool Student::operator!=(Student const &s1)
{
  return this->m_id != s1.m_id;
}

bool Student::operator==(Student const &s1)
{
  return (this->m_id == s1.m_id);
}

bool Student::operator>(Student const &s1)
{
  return this->m_id > s1.m_id;
}

bool Student::operator>=(Student const &s1)
{
  return this->m_id >= s1.m_id;
}

bool Student::operator<(Student const &s1)
{
  return this->m_id < s1.m_id;
}

bool Student::operator<=(Student const &s1)
{
  return this->m_id <= s1.m_id;
}
