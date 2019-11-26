#include "Faculty.h"
#include "Person.h"

using namespace std;
Faculty::Faculty()
{
  m_id = 0;
  m_name;
  m_level;
  m_department;

}
Faculty::~Faculty(){}

Faculty::Faculty(int id,std::string name, std::string level, std::string department):
m_id(id), m_name(name), m_level(level), m_department(department)
{
  adviseeList = new DoublyLinkedList<int>();
}

void Faculty::addStudent(int studID)
{
  adviseeList->insertFront(studID);
}

int Faculty::removeStudent(int studID)
{
  adviseeList->deletePos(studID);
}

//helper functions

void Faculty::print()
{
  std::cout << "the Faculty ID is: " << getID() << "\n";
  std::cout << "the Faculty name is: " << getName() << "\n";
  std::cout << "the Faculty level is: " << getLevel() << "\n";
  std::cout << "the Faculty's department is: " << getDepartment() << "\n";
  std::cout << "Number of advisees: " << adviseeList->getSize() << "\n";
}

void Faculty::printAdvisee()
{
  //cout << "here in print" << endl;
  //cout << "size" << adviseeList->getSize() << endl;
  adviseeList->printList();
}



//Boolean operators



bool Faculty::operator!= (const Faculty &f1)
{
  return this->m_id != f1.m_id;
}
bool Faculty::operator== (const Faculty &f1)
{
  return this->m_id == f1.m_id;
}
bool Faculty::operator> (const Faculty &f1)
{
  return this->m_id > f1.m_id;
}
bool Faculty::operator>= (const Faculty &f1)
{
  return this->m_id >= f1.m_id;
}
bool Faculty::operator< (const Faculty &f1)
{
  return this->m_id < f1.m_id;
}
bool Faculty::operator<= (const Faculty &f1)
{
  return this->m_id <= f1.m_id;
}
