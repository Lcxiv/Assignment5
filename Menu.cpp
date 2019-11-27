#include <iostream>
#include "masterFaculty.h"
#include "masterStudent.h"
#include "BST_Template.h"
#include "DoublyLinkedList.h"
#include "Faculty.h"
#include "Student.h"
#include "FileReader.h"
#include "Menu.h"
using namespace std;





void Menu::Options(unsigned int &choice)
{
  masterFaculty *mf;
  int id = 0;
  mf->readFromFile("FacultyTable.bin");
  bool notOver = true;

  cout << "Printing all the options possible... " << endl;

  while (notOver)
  {
    cin >> choice;
    cout << "Choice 1: Print all students and their information (sorted by ascending id #)." << endl;

    cout << "Choice 2: Print all faculty and their information (sorted by ascending id #)." << endl;
      if (choice == 2)
      {
        cout << "Printing all faculty's ID in Order..." << endl;
        mf->facultyTree->InOrder(mf->facultyTree->root);
      }
    cout << "Choice 3: Find and display student information given the students id." << endl;
    cout << "Choice 4: Find and display faculty information given the faculty id." << endl;
      if (choice == 4)
      {
        cout << "Please enter the faculty ID you want to display." << endl;
        cin >> id;
        TreeNode<Faculty> *node = new TreeNode<Faculty>();
        node = mf->facultyTree->getNode(id);
        node->getData()->print();
        node->getData()->printAdvisee();

      }
    cout << "Choice 5: Given a student’s id, print the name and info of their faculty advisor." << endl;
      if (choice == 5)
      {
        cout << "Please enter the Student ID you want to retrieve his advisor's informations." << endl;
        TreeNode<Student> *studNode = new TreeNode<Student>();
        cout << "The advisor ID is: " << studNode->getData()->getAdvisorField() << endl;
        TreeNode<Faculty> *fNode = new TreeNode<Faculty>();
        fNode = mf->facultyTree->getNode(studNode->getData()->getAdvisorField());
        fNode->getData()->print();
      }
    cout << "Choice 6: Given a faculty id, print ALL the names and info of his/her advisees." << endl;
      if (choice == 6)
      {
        cout << "Please enter the faculty ID you want to find to get all of his advisees' informations." << endl;
        cin >> id;
        mf->printFaculty(id);
      }
    cout << "Choice 7: Add a new student." << endl;
    cout << "Choice 8: Delete a student." << endl;
    cout << "Choice 9: Add a new faculty member." << endl;
    if (choice == 9)
      mf->createFaculty();
    cout << "Choice 10: Delete a faculty member given the id. " << endl;
    if (choice == 10)
    {
      cout << "Please enter which ID to delete the faculty member that matches." << endl;
      cin >> id;
      mf->deleteFaculty(id);
    }
    cout << "Choice 11: Change a student’s advisor given the student id and the new faculty id." << endl;
    cout << "Choice 12: Remove an advisee from a faculty member given the ids" << endl;
    if (choice == 12)
    {
      cout << "Please enter the ID of the faculty member." << endl;
      cin >> id;
      TreeNode<Faculty> *node = new TreeNode<Faculty>();
      node = mf->facultyTree->getNode(id);
      cout << "Please enter the advisee's ID you want to delete" << endl;
      cin >> id;
      node->getData()->adviseeList->deletePos(id);
    }
    cout << "Choice 13: Rollback your command (Up to 5 times.)";
    cout << "Choice 14: Exit" << endl;
      if (choice == 14)
      {
        cout << "Goodbye." << endl;
        notOver = false;
      }
    cout << "Choose your option based on the action you want to perform." << endl;
  }

}
