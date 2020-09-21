#include "teacher_queue.h"

void TeacherQueue::AddTeacher(Teacher teacher) {
  teachers_.push_back(teacher);
}

void TeacherQueue::DeleteTeacher() {
  if (teachers_.empty()) {
    return;
  }
  for (int i = 0; i < teachers_.size() - 1; i++) {
    std::swap(teachers_[i], teachers_[i + 1]);
  }
  teachers_.pop_back();
}

void TeacherQueue::Iterator::Next() {
  current_++;
}

Teacher* TeacherQueue::Iterator::CurrentItem() {
  return &teacher_queue_->teachers_[current_];
}

bool TeacherQueue::Iterator::IsEnd() {
  return current_ >= teacher_queue_->teachers_.size();
}

TeacherQueue::Iterator* TeacherQueue::CreateIterator() {
  return new Iterator(this);
}

TeacherQueue::Iterator::~Iterator() {
  delete teacher_queue_;
}