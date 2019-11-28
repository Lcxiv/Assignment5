/*
Louis Condevaux
Cindy Ramirez
Section 1
C2305172
Assignment 5
StackEmpty.h
 */
#ifndef _STACKEMPTY_H
#define _STACKEMPTY_H

#include "RuntimeException.h"
#include <iostream>
#include<string>
using namespace std;

/**
 * [StackEmpty Returns an error if the stack is empty ]
 * @param err [string]
 */
class StackEmpty:public RuntimeException{
public:
  StackEmpty(const string& err): RuntimeException(err){}

};
#endif
