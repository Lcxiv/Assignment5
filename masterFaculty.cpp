#include "masterFaculty.h"
using namespace std;

masterFaculty::masterFaculty(){
  BST<Faculty> *facultyTree = NULL;
  //Faculty *facultyStaff = NULL;
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
  facultyTree->deleteNode(node->getKey());
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
  int id, numAdvisees, idAdvisees = 0;
  int count = 0;
  ifstream fs;
  Faculty *facultyStaff;
  TreeNode<Faculty> *nodeFaculty;
  bool addMore = true;
  char decision;

  if (fileExists(name)) //calls boolean function to check if a file with the name exists
  {
    fs.open(name); //open the file
      if (fs) //checks if the file is actually working
      {
        while(getline(fs,line)) // reading the file and extracting the values to create a faculty member
        {
          id = stoi(line);
          cout << "The id is: " << id << endl;

          getline(fs,line);
          n = line;
          cout << "Name: " << n << endl;

          getline(fs,line);
          level = line;
          cout << "Level: " << level << endl;

          getline(fs,line);
          department = line;
          cout << "Department: " << department << endl;

          getline(fs,line);
          numAdvisees = stoi(line);
          cout << "Number of advisees: " << numAdvisees << endl;
          facultyStaff = new Faculty (id, n, level, department);

          for (int i = 0; i < numAdvisees; i++) //for loop based on the number of advisees to add
          {
            cout << "Advisee's ID number " << i+1 << ":" << endl;
            getline(fs,line);
            idAdvisees = stoi(line);
            cout << idAdvisees << endl;
            facultyStaff->addStudent(idAdvisees);
          }
        }
        fs.close(); // not necessary but kept in case
      }else
      {
        cout << "An error occured while opening the file." << endl;
      }

      //place where the faculty member is added to the tree

      nodeFaculty = new TreeNode<Faculty>(facultyStaff->getID(), facultyStaff);
      facultyTree->Insert(nodeFaculty);
  }else //creating from scratch the faculty person
  {
    //enum decision {yes = "YES", no = "NO"};

    //Asking the User to insert their own values for the faculty member

    while (addMore) // boolean set to true
    {
      cout << "No file called " << name << " has been found."
      << "Please enter your values to create a faculty Person." << endl;

      cout << "Enter the ID of the faculty member: " << endl;
      cin >> id;

      cout << "Enter the name of the faculty member: " << endl;
      cin >> n;

      cout << "Enter the level of the faculty member: " << endl;
      cin >> level;

      cout << "Enter the department of the faculty member: " << endl;
      cin >> department;

      facultyStaff = new Faculty(id,n,level,department);

      cout << "Enter the number of advisees you want to add for this faculty member: " << endl;
      cin >> numAdvisees;

      for (int i = 0; i < numAdvisees; i++)
      {
        cout << "Enter the ID of the student number " << i+1 << ":" << endl;
        cin >> idAdvisees;
        facultyStaff->addStudent(idAdvisees);
      }
      cout << "The process to add a faculty member is complete." << endl;

      nodeFaculty = new TreeNode<Faculty>(facultyStaff->getID(), facultyStaff); //creating a new treeNode to insert it inside the tree with a specific ID.
      facultyTree->Insert(nodeFaculty); //inserting the node inside the tree

      //checking if the User wants to create another faculty member

      cout << "Would you like to add another faculty member? Y/N" << endl;
      cin >> decision;
      //decision.toupper();
      if (decision == 'Y' || decision == 'y')
        addMore = true;
      else if (decision == 'N' || decision == 'n')
      {
        cout << "Thank you, your faculty member has been added. Exiting..." << endl;
        addMore = false;
      }
      else
      {
        cout << "Please enter a valid input (Y/N)" << endl;
        cin >> decision;
      }
    }
  }
}

bool masterFaculty::fileExists(const string &filename)
{
  ifstream fs(filename);
  return fs.good();
}

void masterFaculty::writeFile(string name){}
