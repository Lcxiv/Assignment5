#include<iostream>
#include "Student.h"
#include "Person.h"


// Student::Student(){
//   // m_id = 0;
//   // m_name;
//   // m_level;
//   // m_majorField;
//   // m_studentGPA = 0;
//   // m_advisorField = 0;
// }
Student::~Student(){}

Student::Student(int id,std::string name, std::string level, std::string majorF, double GPAtotal, int advisorF):
m_id(id),m_name(name), m_level(level), m_majorField(majorF), m_studentGPA(GPAtotal), m_advisorField(advisorF){};


//member functions

bool Student::GreaterThan(int &comp1, int &comp2)
{
  if (comp1 > comp2)
  {
    std::cout<<"The student A is superior than student B"<<"\n";
    return true;
  }
}
bool Student::compareSTR(std::string &a, std::string &b)
{

  if (a == "Freshman" && b == "Freshman") return true;
  else if (a == "Sophomore" && b == "Freshman") return true;
  //finish it
}
void Student::print()
{
  std::cout<<"the Student's ID is: "<<getID()<<"\n";
  std::cout<<"the Student's advisor is: "<<getAdvisorField()<<"\n";
  std::cout<<"the Student's GPA is: "<<getGPA()<<"\n";
  std::cout<<"the Student's field is: "<<getName()<<"\n";
  std::cout<<"the Student's level is: "<<getLevel()<<"\n";
  std::cout<<"the Student's major is: "<<getMajorField()<<"\n";
}
