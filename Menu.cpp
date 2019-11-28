/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
Menu.cpp
 */

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



/**
 * [Menu::Options is the same as a main with all the possibilities added into one method that will be called into the main]
 * @param choice [description]
 */

void Menu::Options(unsigned int choice)
{
  masterFaculty *mf = new masterFaculty();
  masterStudent *ms = new masterStudent();
  int id = 0;

  mf->readFromFile("FacultyTable.bin");
  ms->readFromFile("StudentTable.bin");

  bool notOver = true;
  cout << "Choose your option based on the action you want to perform." << endl;


  while (notOver)
  {
    //cin >> choice;
    //cout << "Choice 1: Print all students and their information (sorted by ascending id #)." << endl;
      if (choice == 0)
      {
        cout << "Printing all the options possible... " << endl;
        cout << "Choice 1: Print all students and their information (sorted by ascending id #)." << endl;
        cout << "Choice 2: Print all faculty and their information (sorted by ascending id #)." << endl;
        cout << "Choice 3: Find and display student information given the students id." << endl;
        cout << "Choice 4: Find and display faculty information given the faculty id." << endl;
        cout << "Choice 5: Given a student’s id, print the name and info of their faculty advisor." << endl;
        cout << "Choice 6: Given a faculty id, print ALL the names and info of his/her advisees." << endl;
        cout << "Choice 7: Add a new student." << endl;
        cout << "Choice 8: Delete a student." << endl;
        cout << "Choice 9: Add a new faculty member." << endl;
        cout << "Choice 10: Delete a faculty member given the id. " << endl;
        cout << "Choice 11: Change a student’s advisor given the student id and the new faculty id." << endl;
        cout << "Choice 12: Remove an advisee from a faculty member given the ids" << endl;
        cout << "Choice 13: Rollback your command (Up to 5 times.)" << endl;
        cout << "Choice 14: Exit" << endl;
      }
      else if (choice == 1)
      {
        cout << "Printing all Students' ID in Order..." << endl;
        ms->studentTree->InOrder(ms->studentTree->root);
        cout << "For more options, enter 20 (PreOrder), 40(PostOrder), or 0 to get out" << endl;
        int order;
        cin >> order;
        if (order == 20) ms->studentTree->PreOrder(ms->studentTree->root);
        else if(order == 40) ms->studentTree->PostOrder(ms->studentTree->root);
        else
        {
          cout << "Please enter your new choice: " << endl;
          cin >> choice;
        }
      }
    //cout << "Choice 2: Print all faculty and their information (sorted by ascending id #)." << endl;
      else if (choice == 2)
      {
        cout << "Printing all faculty's ID in Order..." << endl;
        mf->facultyTree->InOrder(mf->facultyTree->root);
        cout << "For more options, enter 20 (PreOrder), 40(PostOrder), or 0 to get out" << endl;
        int order;
        cin >> order;
        if (order == 20) mf->facultyTree->PreOrder(mf->facultyTree->root);
        else if(order == 40) mf->facultyTree->PostOrder(mf->facultyTree->root);
        else
        {
          cout << "Please enter your new choice: " << endl;
          cin >> choice;
        }
      }
    //cout << "Choice 3: Find and display student information given the students id." << endl;
      else if (choice == 3)
      {
        cout << "Please enter the Student ID you want to display." << endl;
        cin >> id;
        TreeNode<Student> *node = new TreeNode<Student>();
        if (ms->Search(id))
        {
          node = ms->studentTree->getNode(id);
          node->getData()->print();
        }
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 4: Find and display faculty information given the faculty id." << endl;
      else if (choice == 4)
      {
        cout << "Please enter the faculty ID you want to display." << endl;
        cin >> id;
        TreeNode<Faculty> *node = new TreeNode<Faculty>();
        if (mf->Search(id))
        {
          node = mf->searchFaculty(id);
          node->getData()->print();
          node->getData()->printAdvisee();
        }
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 5: Given a student’s id, print the name and info of their faculty advisor." << endl;
      else if (choice == 5)
      {
        int studAdvisorID;
        cout << "Please enter the Student ID you want to retrieve his advisor's informations." << endl;
        cin >> id;
        TreeNode<Student> *nodeS = new TreeNode<Student>();
        if (ms->Search(id))
        {
          nodeS = ms->searchStudent(id);
          studAdvisorID = nodeS->getData()->getAdvisorField();
          TreeNode<Faculty> *nodeF = new TreeNode<Faculty>();
          nodeS->getData()->print();
          if (mf->Search(studAdvisorID))
          {
            nodeF = mf->searchFaculty(id);
            nodeF->getData()->print();
            nodeF->getData()->printAdvisee();
          }
        }
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 6: Given a faculty id, print ALL the names and info of his/her advisees." << endl;
      else if (choice == 6)
      {
        cout << "Please enter the Faculty ID:" << endl;
        cin >> id;
        TreeNode<Faculty> *nodeF = new TreeNode<Faculty>();
        TreeNode<Student> *nodeStud = new TreeNode<Student>();
        int adviseeNum;
        int studLengthID;


        if (mf->Search(id))
        {
          nodeF = mf->searchFaculty(id);
          studLengthID = nodeF->getData()->getSize();
          nodeF->getData()->printAdvisee();
          //cout << "here" << endl;

          if (ms->Search(nodeF->getData()->adviseeList->getFirst()))
          {
            nodeStud = ms->searchStudent(nodeF->getData()->adviseeList->getFirst());
            nodeStud->getData()->print();
            nodeStud = ms->searchStudent(nodeF->getData()->adviseeList->getLast());
            nodeStud->getData()->print();
          }
        }
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 7: Add a new student." << endl;
      else if (choice == 7)
      {
        ms->createStudent();
        //ms->readFromFile("StudentTable.bin");
        ms->addStack();
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 8: Delete a student." << endl;
      else if (choice == 8)
      {
        cout << "Please enter which ID in order to delete the Student that matches." << endl;
        cin >> id;
        ms->deleteStudent(id);
        ms->addStack();
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 9: Add a new faculty member." << endl;
    else if (choice == 9)
    {
      mf->createFaculty();
      mf->addStack();
      cout << "Please enter your new choice: " << endl;
      cin >> choice;
    }
    //cout << "Choice 10: Delete a faculty member given the id. " << endl;
    else if (choice == 10)
    {
      cout << "Please enter which ID in order to delete the faculty member that matches." << endl;
      cin >> id;
      mf->deleteFaculty(id);
      mf->addStack();
      cout << "Please enter your new choice: " << endl;
      cin >> choice;
    }
    //cout << "Choice 11: Change a student’s advisor given the student id and the new faculty id." << endl;
    else if (choice == 11)
    {
      cout << "Please enter the Student ID: " << endl;
      cin >> id;
      TreeNode<Student> *nodeS = new TreeNode<Student>();
      if (ms->Search(id))
      {
        nodeS = ms->searchStudent(id);
        cout << "Please enter the Advisor ID you want to assign." << endl;
        int newID;
        cin >> newID;
        nodeS->getData()->setAdvisor(newID);
        cout << "The Student has been correctly reassigned." << endl;
      }
      ms->addStack();
      cout << "Please enter your new choice: " << endl;
      cin >> choice;
    }
    //cout << "Choice 12: Remove an advisee from a faculty member given the ids" << endl;
    else if (choice == 12)
    {
      int idToDelete;
      cout << "Please enter the ID of the faculty member." << endl;
      cin >> id;
      TreeNode<Faculty> *nodeF = new TreeNode<Faculty>();
      if (mf->Search(id))
      {
        cout << "Please enter the Student ID you wish to delete" << endl;
        nodeF->getData()->adviseeList->deletePos(idToDelete);
      }
      mf->addStack();
      cout << "Please enter your new choice: " << endl;
      cin >> choice;
    }
    //cout << "Choice 13: Rollback your command (Up to 5 times.)" << endl;
    else if (choice == 13)
    {
      cout << "Enter the number of times you want to rollback: " << endl;
      unsigned int numRoll;
      cin >> numRoll;
      for (int i = 0; i < numRoll; i++)
        mf->deleteStack();
        ms->deleteStack();
    }
    //cout << "Choice 14: Exit" << endl;
      else if (choice == 14)
      {
        cout << "Goodbye." << endl;
        ms->saveFile();
        mf->saveFile();
        notOver = false;
      }
  }

}
