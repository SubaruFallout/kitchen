#ifndef STUDENT_H_
#define STUDENT_H_

#include <string>

#include "element.h"

class Student : public Element {
 public:
  Student(std::string new_name) : name_(new_name) {}

  void Accept(AbstractVisitor& v);

 private:
  std::string name_;
};

#endif  // STUDENT_H_
