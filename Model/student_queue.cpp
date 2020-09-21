#include "student_queue.h"

void StudentQueue::AddStudent(Student student) {
  students_.push_back(student);
}

void StudentQueue::DeleteStudent() {
  if (students_.empty()) {
    return;
  }
  for (int i = 0; i < students_.size() - 1; i++) {
    std::swap(students_[i], students_[i + 1]);
  }
  students_.pop_back();
}

void StudentQueue::Iterator::Next() {
  current_++;
}

Student* StudentQueue::Iterator::CurrentItem() {
  return &student_queue_->students_[current_];
}

bool StudentQueue::Iterator::IsEnd() {
  return current_ >= student_queue_->students_.size();
}

StudentQueue::Iterator* StudentQueue::CreateIterator() {
  return new Iterator(this);
}

StudentQueue::Iterator::~Iterator() {
  delete student_queue_;
}
