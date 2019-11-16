#include<iostream>
#include "Faculty.h"
#include "Student.h"
#include "BST_Template.h"
#include "DoublyLinkedList.h"
using namespace std;



int main(int argc, char const *argv[]) {
BST<Student> *tree = new BST<Student>();
Student *a = new Student(1,"Crean","Junior","Sociology",3.00,2012);
Student *b = new Student(2,"blulb","Senior","Dance",2.00,0003);
Student *c = new Student(3,"blibl","Freshman","Business",1.50,36);
Student *d = new Student(4,"arewt","Lolol","Shuffle",4.00,534);


cout << "HERE "<< a->getID() << endl;
cout << "HERE2 "<< a->getName() << endl;
int studID = a->getID();
int* numID = &studID;

TreeNode<Student> *treeStud1 = new TreeNode<Student>(a->getID(),a);
TreeNode<Student> *treeStud2 = new TreeNode<Student>(b->getID(),b);
TreeNode<Student> *treeStud3 = new TreeNode<Student>(c->getID(),c);
TreeNode<Student> *treeStud4 = new TreeNode<Student>(d->getID(),d);
cout<<"KEY " <<treeStud1->getKey()<<endl;
tree->Insert(treeStud1);
//tree->recPrint(treeStud1);
// tree->getMax();
tree->printTree();
tree->Insert(treeStud2);
tree->Insert(treeStud3);
// tree->getMax();
// tree->printTree();

tree->Insert(treeStud4);
tree->printTree();

//tree->~BST();
//cout<<tree->Search(10)<<endl;
//tree->recPrint(treeStud1);// TreeNode<Student*> *z = b;
//Student &d = b;
//TreeNode<Student*> c = new TreeNode<Student*>(b);
//tree->Insert(z);
// Student* a = new Student(0002, "Marc","Junior","Sociology",3.00,2012);
// a->print();

  return 0;
}
