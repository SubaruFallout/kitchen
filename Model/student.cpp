#include "student.h"

void Student::Accept(AbstractVisitor &v) {
  v.Visit(*this);
}
