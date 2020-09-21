#ifndef ABSTRACT_VISITOR_H_
#define ABSTRACT_VISITOR_H_

class Student;
class Teacher;

class AbstractVisitor {
 public:
  virtual void Visit(Student &student) = 0;
  virtual void Visit(Teacher &teacher) = 0;

  virtual ~AbstractVisitor() = default;
};

#endif  // ABSTRACT_VISITOR_H_
