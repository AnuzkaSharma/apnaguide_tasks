cmake_minimum_required(VERSION 3.28)
project(apnaguide_tasks)

set(CMAKE_CXX_STANDARD 14)

add_executable(${PROJECT_NAME}_simple_calculator simple_calculator.cpp
        banking_system.cpp
        library_system.cpp
        chess_game.cpp)
add_executable(${PROJECT_NAME}_student_grade_tracker student_grade_tracker.cpp)

target_compile_definitions(${PROJECT_NAME}_simple_calculator PUBLIC -DSIMPLE_CALCULATOR_BUILD)
target_compile_definitions(${PROJECT_NAME}_student_grade_tracker PUBLIC -DSTUDENT_GRADE_TRACKER_BUILD)

add_custom_target(${PROJECT_NAME} DEPENDS ${PROJECT_NAME}_simple_calculator ${PROJECT_NAME}_student_grade_tracker)