#ifndef TEACHER_H_
#define TEACHER_H_

#include <string>

#include "element.h"

class Teacher : public Element {
 public:
  Teacher(std::string new_name) : name_(new_name) {}

  void Accept(AbstractVisitor& v);

 private:
  std::string name_;
};

#endif  // TEACHER_H_
