#ifndef FILEREADER_H
#define FILEREADER_H
#include <iostream>
#include <fstream>

class FileReader{
protected:
  std::string fileName;
public:
  FileReader();
  ~FileReader();
  virtual void openFile(std::string name);
  virtual void writeFile(std::string name);
  void setFileName(std::string n){fileName = n;};
  std::string getName(){return fileName;};

};
#endif
