#include "visitor.h"

void Visitor::Visit(Student& student) {
  text_ = "Go away";
  color_.red = 0;
  color_.green = 0;
  color_.blue = 255;
}

void Visitor::Visit(Teacher& teacher) {
  text_ = "Here your mushroom soup";
  color_.red = 255;
  color_.blue = 0;
  color_.green = 0;
}

std::string Visitor::GetText() {
  return text_;
}

int Visitor::GetColor() {
  return color_.blue * 256 * 256 + color_.green * 256 + color_.red;
}

void Visitor::Clear() {
  text_ = "Welcome to the Kitchen buddy";
  color_.red = 255;
  color_.green = 255;
  color_.blue = 255;
}