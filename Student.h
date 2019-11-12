#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>


class Student
{
  int studentID, advisorField;
  double studentGPA;
  std::string nameField, levelField, majorField;

public:
  Student();
  Student(int studID,std::string nameF, std::string levelF, std::string majorF, double GPAtotal, int advisorF);
  ~Student();

  int getStudentID(){return studentID;};
  int getAdvisorField(){return advisorField;};
  double getGPA(){return studentGPA;};
  std::string getNameField(){return nameField;};
  std::string getLevelField(){return levelField;};
  std::string getMajorField(){return majorField;};
  bool GreaterThan(int &comp1, int &comp2);
  bool compareSTR(std::string &a, std::string &b);
  void print();
};
#endif
