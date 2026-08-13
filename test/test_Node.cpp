#include <gtest/gtest.h>
#include "../src/include/cppNode.hpp"
#include <memory>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Basic_Node_Test : public testing::Test
{
};

TEST_F(Basic_Node_Test, test_constructor) {}

TEST_F(Basic_Node_Test, test_data) {}

TEST_F(Basic_Node_Test, test_set) {}

TEST_F(Basic_Node_Test, test_assign) {}

TEST_F(Basic_Node_Test, test_equals) {}

TEST_F(Basic_Node_Test, test_not_equal) {}

class Linear_Node_Test : public testing::Test
{

};

TEST_F(Linear_Node_Test, test_next) {}

TEST_F(Linear_Node_Test, test_prev) {}

TEST_F(Linear_Node_Test, test_set_next) {}

TEST_F(Linear_Node_Test, test_set_prev) {}

class Priority_Node_Test : public testing::Test {

}; 

TEST_F(Priority_Node_Test, test_priority) {}

TEST_F(Priority_Node_Test, test_set_priority) {}

TEST_F(Priority_Node_Test, test_lt) {}

TEST_F(Priority_Node_Test, test_gt) {}

TEST_F(Priority_Node_Test, test_le) {}

TEST_F(Priority_Node_Test, test_ge) {}

TEST_F(Priority_Node_Test, test_equals) {}

TEST_F(Priority_Node_Test, test_ne) {}

class N_Tree_Node_Test : public testing::Test {

};


TEST_F(N_Tree_Node_Test, test_add_child) {}

TEST_F(N_Tree_Node_Test, test_set_parent) {}

TEST_F(N_Tree_Node_Test, test_remove_child) {}

TEST_F(N_Tree_Node_Test, test_remove_parent) {}

TEST_F(N_Tree_Node_Test, test_children) {}

TEST_F(N_Tree_Node_Test, test_parent) {}

TEST_F(N_Tree_Node_Test, test_size) {}

class Binary_Tree_Test : public testing::Test {

};

TEST_F(Binary_Tree_Test, test_left) {}

TEST_F(Binary_Tree_Test, test_right) {}

TEST_F(Binary_Tree_Test, test_parent) {}

TEST_F(Binary_Tree_Test, test_set_left) {}

TEST_F(Binary_Tree_Test, test_set_right) {}

TEST_F(Binary_Tree_Test, test_add_child) {}

TEST_F(Binary_Tree_Test, test_remove_left) {}

TEST_F(Binary_Tree_Test, test_remove_right) {}

class Balanced_Tree_Node_Test : public testing::Test {

};

TEST_F(Balanced_Tree_Node_Test, test_height) {}

TEST_F(Balanced_Tree_Node_Test, test_set_height) {}

TEST_F(Balanced_Tree_Node_Test, test_balance_factor) {}

TEST_F(Balanced_Tree_Node_Test, test_set_balance_factor) {}

TEST_F(Balanced_Tree_Node_Test, test_check_balance) {}

TEST_F(Balanced_Tree_Node_Test, test_rebalance) {}

TEST_F(Balanced_Tree_Node_Test, test_left_rotate) {}

TEST_F(Balanced_Tree_Node_Test, test_right_rotate) {}

TEST_F(Balanced_Tree_Node_Test, test_check_height) {}

class Heap_Node_Test : public testing::Test {

};

TEST_F(Heap_Node_Test, test_priority) {}

TEST_F(Heap_Node_Test, test_set_priority) {}

class Graph_Node_Test : public testing::Test {

};

TEST_F(Graph_Node_Test, test_add_edge) {}

TEST_F(Graph_Node_Test, test_remove_edge) {}

TEST_F(Graph_Node_Test, test_edges) {}

class Weighted_Graph_Node_Test : public testing::Test 
{ 

};

TEST_F(Weighted_Graph_Node_Test, test_weight) {}

TEST_F(Weighted_Graph_Node_Test, test_add_edge) {}

TEST_F(Weighted_Graph_Node_Test, test_remove_edge) {}

TEST_F(Weighted_Graph_Node_Test, test_weights) {}
