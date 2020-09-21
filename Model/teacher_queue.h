#ifndef TEACHER_QUEUE_H_
#define TEACHER_QUEUE_H_

#include <vector>

#include "teacher.h"

class TeacherQueue {
 public:
  TeacherQueue() = default;

  void AddTeacher(Teacher teacher);
  void DeleteTeacher();

  class Iterator {
   public:
    Iterator(TeacherQueue* new_teacher_queue)
        : teacher_queue_(new_teacher_queue), current_(0) {}

    void Next();
    Teacher* CurrentItem();
    bool IsEnd();

    ~Iterator();

   private:
    TeacherQueue* teacher_queue_;
    int current_;
  };

  Iterator* CreateIterator();

 private:
  std::vector<Teacher> teachers_;
};

#endif  // TEACHER_QUEUE_H_
