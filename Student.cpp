#include<iostream>
#include "Student.h"


Student::Student(){
  studentID = -1;
  nameField;
  levelField;
  majorField;
  studentGPA = 0;
  advisorField = -1;
}

Student::Student(int studID,std::string nameF, std::string levelF, std::string majorF, double GPAtotal, int advisorF):
studentID(studID), nameField(nameF), levelField(levelF), majorField(majorF), studentGPA(GPAtotal), advisorField(advisorF){};


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
  std::cout<<"the Student's ID is: "<<getStudentID()<<"\n";
  std::cout<<"the Student's advisor is: "<<getAdvisorField()<<"\n";
  std::cout<<"the Student's GPA is: "<<getGPA()<<"\n";
  std::cout<<"the Student's field is: "<<getNameField()<<"\n";
  std::cout<<"the Student's level is: "<<getLevelField()<<"\n";
  std::cout<<"the Student's major is: "<<getMajorField()<<"\n";
}
