cmake_minimum_required(VERSION 3.15)
project(Lab_1)

set(CMAKE_CXX_STANDARD 14)

add_executable(Kitchen
        Controller/main.cpp
        Model/student.cpp
        Model/student_queue.cpp
        Model/teacher.cpp
        Model/teacher_queue.cpp
        Model/visitor.cpp
        View/view.cpp)
target_link_libraries(Kitchen "Comctl32.lib")