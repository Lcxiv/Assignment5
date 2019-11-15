/*
Louis Condevaux
Section 1
C2305172
Assignment 4
ListEmpty.h
 */
#ifndef _LISTEMPTY_H
#define _LISTEMPTY_H

#include "RuntimeException.h"
#include <iostream>
#include<string>
using namespace std;

/**
 * [ListEmpty Returns an error if the stack is empty ]
 * @param err [string]
 */
class ListEmpty:public RuntimeException{
public:
  ListEmpty(const string& err): RuntimeException(err){}

};
#endif
