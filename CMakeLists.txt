cmake_minimum_required(VERSION 3.28)
project(apnaguide_tasks)

set(CMAKE_CXX_STANDARD 14)

# Define executables with unique names
add_executable(apnaguide_tasks_simple_calculator simple_calculator.cpp)
add_executable(apnaguide_tasks_student_grade_tracker student_grade_tracker.cpp)

# Set compile definitions for each executable
target_compile_definitions(apnaguide_tasks_simple_calculator PUBLIC -DSIMPLE_CALCULATOR_BUILD)
target_compile_definitions(apnaguide_tasks_student_grade_tracker PUBLIC -DSTUDENT_GRADE_TRACKER_BUILD)

# If you need a "student" target, uncomment the following lines
# add_executable(apnaguide_tasks_student student.cpp)
# target_compile_definitions(apnaguide_tasks_student PRIVATE ...)