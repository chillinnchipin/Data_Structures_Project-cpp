# Project setup
cmake_minimum_required(VERSION 3.25)
project(CPP_Node VERSION 0.0.0)
# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Fetch Google Test
include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
FetchContent_MakeAvailable(googletest)
enable_testing()

# Add executables
add_executable(cpp_node src/cppNode.cpp)
add_executable(test_AVL test/test_AVL.cpp)
add_executable(test_BST test/test_BST.cpp)
add_executable(test_Node test/test_Node.cpp)
add_executable(test_Queue test/test_Queue.cpp)
add_executable(test_search test/test_search.cpp)
add_executable(test_sort test/test_sort.cpp)
add_executable(test_Stack test/test_Stack.cpp)

# Test setup

target_link_libraries(test_AVL GTest::gtest_main)
target_link_libraries(test_BST GTest::gtest_main)
target_link_libraries(test_Node GTest::gtest_main)
target_link_libraries(test_Queue GTest::gtest_main)
target_link_libraries(test_search GTest::gtest_main)
target_link_libraries(test_sort GTest::gtest_main)
target_link_libraries(test_Stack GTest::gtest_main)

include(GoogleTest)
gtest_discover_tests(test_AVL)
gtest_discover_tests(test_BST)
gtest_discover_tests(test_Node)
gtest_discover_tests(test_Queue)
gtest_discover_tests(test_search)
gtest_discover_tests(test_sort)
gtest_discover_tests(test_Stack)
