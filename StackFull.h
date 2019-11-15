/*
Louis Condevaux
Section 1
C2305172
Assignment3
StackFull.h
 */
#ifndef _STACKFULL_H
#define _STACKFULL_H

#include "RuntimeException.h"
#include <iostream>
#include<string>
using namespace std;
/**
 * [StackFull Returns an error if the stack is full, not needed in this case since we double the size]
 * @param err [string]
 */
class StackFull:public RuntimeException{
public:
  StackFull(const string& err): RuntimeException(err){}

};
#endif
