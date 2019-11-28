/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
Person.h
 */

#ifndef PERSON_H
#define PERSON_H
#include <iostream>

class Person{
protected:
  int m_id;
  std::string m_name;
  std::string m_level;
  //transaction log databasing //rollback function

public:

  Person();
  virtual ~Person();

  virtual int setID(int id){m_id=id;}
  virtual int getID(){return m_id;};
  virtual std::string getName(){return m_name;};
  virtual std::string getLevel(){return m_level;};
  virtual void print();
};
#endif
