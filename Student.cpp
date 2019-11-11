#include<iostream>
#include "Student.h"
using namespace std;

Student::Student(){
  studentID = NULL;
  nameField = NULL;
  levelField = NULL;
  majorField = NULL;
  studentGPA = NULL;
  advisorField = NULL;
}

Student::Student(int studID,string nameF, string levelF = "Freshman", string majorF = "Undecided", double GPAtotal, int advisorF): studentID(studID), nameField(nameF), levelField(levelF), majorField(majorF), studentGPA(GPAtotal), advisorField(advisorF){};
