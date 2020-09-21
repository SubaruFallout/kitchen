#include "teacher.h"

void Teacher::Accept(AbstractVisitor &v) {
  v.Visit(*this);
}
