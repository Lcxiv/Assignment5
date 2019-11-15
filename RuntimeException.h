/*
Louis Condevaux
Section 1
C2305172
Assignment3
RuntimeException.h
 */
#ifndef _RuntimeException_H
#define _RuntimeException_H

#include<exception>
#include <iostream>
#include <string>
using namespace std;

/**
 * [RuntimeException Class to create my own exceptions]
 * @param err [string]
 */
class RuntimeException
{
private:
string errorMSG;
public:
  RuntimeException(const string& err)
  {errorMSG = err;}
  string getMessage()const {return errorMSG;}
};
#endif
