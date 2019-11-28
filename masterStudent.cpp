/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
masterStudent.cpp
 */

#include "masterStudent.h"

masterStudent::masterStudent()
{
  BST<Student> *studentTree = NULL;

}

masterStudent::~masterStudent()
{
  delete studentTree;
}

void masterStudent::addStudent(TreeNode<Student> *node)
{
  studentTree->Insert(node);
}

bool masterStudent::Search(int idS)
{
  studentTree->Search(idS);
}

TreeNode<Student>* masterStudent::searchStudent(int idS)
{
  studentTree->getNode(idS);
}

void masterStudent::createStudent()
{
  bool addMore = true;
  string n, level, majorF;
  int id, advisorID = 0;
  double studGPA;
  Student *stud;
  TreeNode<Student> *nodeStudent;
  char decision;
  while (addMore) // boolean set to true
  {
    cout << "Please enter your values to create a Student." << endl;

    cout << "Enter the ID of the Student: " << endl;
    cin >> id;

    cout << "Enter the name of the Student: " << endl;
    cin >> n;

    cout << "Enter the level of the Student: " << endl;
    cin >> level;

    cout << "Enter the major of the Student: " << endl;
    cin >> majorF;

    cout << "Enter the Student's GPA: " << endl;
    cin >> studGPA;

    cout << "Enter the Student's advisor ID: " << endl;
    cin >> advisorID;

    stud = new Student(id,n,level,majorF,studGPA,advisorID);

    cout << "The process to add a Student member is complete." << endl;

    nodeStudent = new TreeNode<Student>(stud->getID(), stud); //creating a new treeNode to insert it inside the tree with a specific ID.
    studentTree->Insert(nodeStudent); //inserting the node inside the tree

    //checking if the User wants to create another Student

    cout << "Would you like to add another Student? Y/N" << endl;
    cin >> decision;
    //decision.toupper();
    if (decision == 'Y' || decision == 'y')
      addMore = true;
    else if (decision == 'N' || decision == 'n')
    {
      cout << "Thank you, your Student has been added. Exiting..." << endl;
      addMore = false;
    }
    else
    {
      cout << "Please enter a valid input (Y/N)" << endl;
      cin >> decision;
    }
  }
}

void masterStudent::deleteStudent(unsigned int id)
{
  studentTree->deleteNode(id);
}

bool masterStudent::fileExists(const string &filename)
{
  ifstream fs(filename);
  return fs.good();
}

void masterStudent::print()
{
  studentTree->printTree();
}

void masterStudent::readFromFile(const string &name)
{
  bool addMore = true;
  string n, level, majorF, line;
  int id, advisorID = 0;
  double studGPA;
  Student *stud;
  TreeNode<Student> *nodeStudent;
  char decision;
  ifstream fs;
  if (fileExists(name)) //calls boolean function to check if a file with the name exists
  {
    fs.open(name); //open the file
      if (fs) //checks if the file is actually working
      {
        while(getline(fs,line)) // reading the file and extracting the values to create a faculty member
        {
          id = stoi(line);
          //cout << "The ID is: " << id << endl;

          getline(fs,line);
          n = line;
          //cout << "Name: " << n << endl;

          getline(fs,line);
          level = line;
          //cout << "Level: " << level << endl;

          getline(fs,line);
          majorF = line;
          //cout << "Major: " << majorF << endl;

          getline(fs,line);
          studGPA = stod(line);
          //cout << "GPA: " << studGPA << endl;

          getline(fs,line);
          advisorID = stoi(line);
          //cout << "Advisor ID: " << advisorID << endl;


          stud = new Student (id, n, level, majorF, studGPA, advisorID);
          nodeStudent = new TreeNode<Student>(stud->getID(), stud);
          studentTree->Insert(nodeStudent);
        }
        fs.close(); // not necessary but kept in case
      }else
      {
        cout << "An error occured while opening the file." << endl;
      }

      //place where the Student is added to the tree


  }else //creating from scratch the Student if there is no file to pull from
  {
    createStudent();
  }
}

void masterStudent::writeFile(const string &name, TreeNode<Student> *node)
{
  ofstream of;
  of.open(name, ios::out | ios::app);
  if (!of)
  {
    cout << "An error occured while trying to open the file" << endl;
  }
  else
  {
    if (of.is_open())
    {
      //cout << "Printing data into " << name << "..... \n" << endl;
      if (node == nullptr)
        return;
      else
      {
        //of.write((char *)node)
        if (node != NULL)
        {
          //of.open(name);
          //cout << "Printing ID \n ------- \n" << node->getData()->getID() << "\n" << endl;
          of << node->getData()->getID() << "\n";

          //cout << "Printing Name \n ------- \n" << node->getData()->getName() << "\n" << endl;
          of << node->getData()->getName() << "\n";

          //cout << "Printing Level \n ------- \n" << node->getData()->getLevel() << "\n" << endl;
          of << node->getData()->getLevel() << "\n";

          //cout << "Printing Major \n ------- \n" << node->getData()->getMajorField() << "\n" << endl;
          of << node->getData()->getMajorField() << "\n";

          //cout << "Printing GPA  \n  ------- \n" << node->getData()->getGPA() << "\n" << endl;
          of << node->getData()->getGPA() << "\n";

          //cout << "Printing Advisor ID \n  ------- \n" << node->getData()->getAdvisorField() << "\n" << endl;
          of << node->getData()->getAdvisorField() << "\n";

          of.close();
          if (node->left != NULL)
            writeFile(name, node->left); //following recPrint idea to make it recursive and visit all the nodes
            else if (node->right != NULL)
              writeFile(name, node->right);
        }
      }
    }

  }
}

 void masterStudent::saveFile()
{
  writeFile("SaveStudentTable.bin", studentTree->root);
}

void masterStudent::addStack()
{
  studentStack->push(studentTree);
}

void masterStudent::deleteStack()
{
  studentStack->pop();
}
