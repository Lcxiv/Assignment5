#include "masterFaculty.h"
using namespace std;

masterFaculty::masterFaculty(){
  BST<Faculty> *facultyTree = NULL;
  Faculty *facultyStaff = NULL;
};

masterFaculty::~masterFaculty(){
  delete facultyTree;
}

void masterFaculty::addFaculty(TreeNode<Faculty> *node)
{
  facultyTree->Insert(node);
}

void masterFaculty::deleteFaculty(TreeNode<Faculty> *node)
{
  facultyTree->deleteNode(facultyStaff->getID());
}

bool masterFaculty::searchFaculty(int id)
{
  facultyTree->Search(id);
}

void masterFaculty::print()
{
  facultyTree->printTree();
}

void masterFaculty::readFromFile(string name)
{
  string n, level, department, line;
  int id, numAdvisees, idAdvisees;
  int count = 0;
  ifstream fs;
  int lineNum = fs.tellg();
  fs.open(name);
  while(!getline(fs, line).eof())
  {
    if (fs.is_open())
    {
      //getline(fs,line);
      id = atoi(line.c_str());
      cout << "The id is: " << id << endl;
      n = line.c_str();
      cout << "Name: " << name << endl;
      level = atoi(line.c_str());
      cout << "Level: " << level << endl;
      getline(fs,line);
      department = atoi(line.c_str());
      cout << "Department: " << department << endl;

    }else
    {
      cout << "An error occured while opening the file." << endl;
    }
    fs.close();


  }
}

void masterFaculty::writeFile(string name){}
