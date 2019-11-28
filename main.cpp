/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
main.cpp
 */

#include<iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST_Template.h"
#include "DoublyLinkedList.h"
#include "masterFaculty.h"
#include "FileReader.h"
#include "masterStudent.h"
#include "Menu.h"
using namespace std;



int main(int argc, char const *argv[]) {
// BST<Student> *tree = new BST<Student>();
// BST<Faculty> *treeF = new BST<Faculty>();
//
// Student *a = new Student(1,"Crean","Junior","Sociology",3.00,2012);
// Student *b = new Student(2,"blulb","Senior","Dance",2.00,0003);
// Student *c = new Student(3,"blibl","Freshman","Business",1.50,36);
// Student *d = new Student(4,"arewt","Lolol","Shuffle",4.00,534);
// Student *comp = new Student(1,"Crean","Junior","Sociology",3.00,2012);
//
//
// Faculty *f = new Faculty(0003, "Mike", "Tenured", "Psychology");
// f->addStudent(a->getID());
// f->addStudent(d->getID());
//
// cout << "HERE "<< a->getID() << endl;
// cout << "HERE2 "<< a->getName() << endl;
// int studID = a->getID();
// int* numID = &studID;
//
// TreeNode<Student> *treeStud1 = new TreeNode<Student>(a->getID(),a);
// TreeNode<Student> *treeStud2 = new TreeNode<Student>(b->getID(),b);
// TreeNode<Student> *treeStud3 = new TreeNode<Student>(c->getID(),c);
// TreeNode<Student> *treeStud4 = new TreeNode<Student>(d->getID(),d);
// cout<<"KEY " <<treeStud1->getKey()<<endl;
// tree->Insert(treeStud1);
// //tree->recPrint(treeStud1);
// // tree->getMax();
// tree->printTree();
// tree->Insert(treeStud2);
// tree->Insert(treeStud3);
// // tree->getMax();
// // tree->printTree();
//
// tree->Insert(treeStud4);
// tree->printTree();
//
// TreeNode<Faculty> *nodeFaculty = new TreeNode<Faculty>(f->getID(),f);
// treeF->Insert(nodeFaculty);
// //f->print();
//  f->printAdvisee();
//  cout<< "Comparing two ID's: " << a->operator==(*c) << endl;
//  treeF->deleteNode(f->getID());
// treeF->printTree();
// masterFaculty *mf = new masterFaculty();
// mf->readFromFile("FacultyTable.bin");
//mf->createFaculty();
//mf.saveFile();
//int id;
// masterStudent ms;
// ms.readFromFile("StudentTable.bin");
//ms.saveFile();
// cout << "Please enter the faculty ID you want to display." << endl;
// cin >> id;
// TreeNode<Faculty> *node = new TreeNode<Faculty>();
//mf->searchFaculty(id);
// node = mf->facultyTree->getNode(id);
// node->getData()->print();
// node->getData()->printAdvisee();
// if (mf->Search(id))
// {
//   node = mf->searchFaculty(id);
//   node->getData()->print();
//   node->getData()->printAdvisee();
// }
Menu m;

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
int pick = 0;
cout << "Choose your option: " << endl;
cout << "Remember, to display all the possible options, enter 0 when your new choice is asked." << endl;
cin >> pick;
m.Options(pick);


  return 0;
}
