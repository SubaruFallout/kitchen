#ifndef VISITOR_H_
#define VISITOR_H_

#include <string>

#include "abstract_visitor.h"

class Visitor : public AbstractVisitor {
 public:
  Visitor() : text_("Welcome to the kitchen buddy") {
    color_.red = 255;
    color_.green = 255;
    color_.blue = 255;
  }

  void Visit(Student& student);
  void Visit(Teacher& teacher);

  std::string GetText();
  int GetColor();
  void Clear();

 private:
  std::string text_;

  struct {
    int red;
    int green;
    int blue;
  } color_;
};

#endif  // VISITOR_H_
