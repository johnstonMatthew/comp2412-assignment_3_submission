cmake_minimum_required(VERSION 3.1)
SET(CMAKE_APP_NAME "MyProjects")

project(${CMAKE_APP_NAME})

set(EXECUTABLE_OUTPUT_PATH ${CMAKE_BINARY_DIR}/bin)

# Add subdirectories, these will serve as "subprojects"
# add_subdirectory(src/CreditCard)
# add_subdirectory(src/LabQuestions/Lab-1)
# add_subdirectory(src/LabQuestions/Lab0)
# add_subdirectory(src/Assignment1/question_1)
# add_subdirectory(src/Assignment1/question_2)
# add_subdirectory(src/Assignment1/question_3)
# add_subdirectory(src/Assignment1/question_4)
# add_subdirectory(src/Assignment1/question_5)
# add_subdirectory(src/Assignment1/question_6)
# add_subdirectory(src/Assignment1/question_7)
# add_subdirectory(src/Assignment1/question_8)
# add_subdirectory(src/Assignment1/question_9)
# add_subdirectory(src/Assignment1/question_10)
# add_subdirectory(src/Assignment2/question_1)
# add_subdirectory(src/Assignment2/question_2)
# add_subdirectory(src/Assignment2/question_3)
# add_subdirectory(src/Assignment2/question_4)
add_subdirectory(src/Assignment3/question_1)
add_subdirectory(src/Assignment3/question_2)
add_subdirectory(src/Assignment3/question_3)
add_subdirectory(src/Assignment3/question_4)
# add_subdirectory(src/SampleAVL)
# add_subdirectory(src/Lab2)
# add_subdirectory(src/Lab3)
# add_subdirectory(src/Lab4)
# Add more subdirectories as needed

# Add the executable (assuming it's named 'my_executable')
# add_executable(my_top_levelexec main.cpp)

# Link the executable with the targets from the subdirectories
# target_link_libraries(my_executable src/CreditCard src/Lab0)
# Link more libraries if there are additional subdirectoriese