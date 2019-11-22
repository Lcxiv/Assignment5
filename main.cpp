#include<iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST_Template.h"
#include "DoublyLinkedList.h"
#include "masterFaculty.h"
#include "FileReader.h"
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
masterFaculty mf;
mf.readFromFile("FacultyTet.txt");

  return 0;
}
