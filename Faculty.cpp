#include "Faculty.h"

Faculty::Faculty()
{
  facultyID = 0;
  name;
  level;
  department;

}

Faculty::Faculty(int id,std::string n, std::string l, std::string d):
facultyID(id), name(n), level(l), department(d)
{

}
