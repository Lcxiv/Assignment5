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
        // cout << "Please enter the Faculty ID:" << endl;
        // cin >> id;
        //
        // TreeNode<Faculty> *nodeF = new TreeNode<Faculty>();
        // TreeNode<Student> *nodeStud = new TreeNode<Student>();
        // int adviseeNum;
        // int studLengthID;
        //
        //
        // if (mf->Search(id))
        // {
        //   nodeF = mf->searchFaculty(id);
        //   studLengthID = nodeF->getData()->getSize();
        //   nodeF->getData()->printAdvisee();
        //   cout << "here" << endl;
        //   cout << nodeF->getData()->adviseeList->getFirst()<<endl;
        //   for (int i = 0; i < studLengthID; i++)
        //   {
        //     adviseeNum = nodeF->getData()->adviseeList->;
        //     cout << "Advisee: " << adviseeNum << endl;
        //     if (ms->Search(adviseeNum))
        //     {
        //       nodeStud = ms->searchStudent(adviseeNum);
        //       nodeStud->getData()->print();
        //     }
        //   }
        // }
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 7: Add a new student." << endl;
      else if (choice == 7)
      {
        ms->createStudent();
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 8: Delete a student." << endl;
      else if (choice == 8)
      {
        cout << "Please enter which ID in order to delete the Student that matches." << endl;
        cin >> id;
        ms->deleteStudent(id);
        cout << "Please enter your new choice: " << endl;
        cin >> choice;
      }
    //cout << "Choice 9: Add a new faculty member." << endl;
    else if (choice == 9)
    {
      mf->createFaculty();
      cout << "Please enter your new choice: " << endl;
      cin >> choice;
    }
    //cout << "Choice 10: Delete a faculty member given the id. " << endl;
    else if (choice == 10)
    {
      cout << "Please enter which ID in order to delete the faculty member that matches." << endl;
      cin >> id;
      mf->deleteFaculty(id);
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
      cout << "Please enter your new choice: " << endl;
      cin >> choice;
    }
    //cout << "Choice 13: Rollback your command (Up to 5 times.)" << endl;
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
