#ifndef STUDENT_QUEUE_H_
#define STUDENT_QUEUE_H_

#include <vector>

#include "student.h"

class StudentQueue {
 public:
  StudentQueue() = default;

  void AddStudent(Student student);
  void DeleteStudent();

  class Iterator {
   public:
    explicit Iterator(StudentQueue* new_student_queue)
        : student_queue_(new_student_queue), current_(0) {}

    void Next();
    Student* CurrentItem();
    bool IsEnd();

    ~Iterator();

   private:
    StudentQueue* student_queue_;
    int current_;
  };

  Iterator* CreateIterator();

 private:
  std::vector<Student> students_;
};

#endif  // STUDENT_QUEUE_H_
