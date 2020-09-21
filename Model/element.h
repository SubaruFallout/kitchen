#ifndef ABSTRACT_ELEMENT_H_
#define ABSTRACT_ELEMENT_H_

#include "abstract_visitor.h"

class Element {
 public:
  virtual void Accept(AbstractVisitor &v) = 0;

  virtual ~Element() = default;
};

#endif  // ABSTRACT_ELEMENT_H_
