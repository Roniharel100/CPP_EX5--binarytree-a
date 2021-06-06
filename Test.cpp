#include "doctest.h"
#include "BinaryTree.hpp"
#include <iostream>
#include <string>
#include <array>

using namespace ariel;
using namespace std;

TEST_CASE("Test int")
{
  BinaryTree<int> int_to_tree;
  // before add root (throw exepction)
  CHECK_THROWS(int_to_tree.add_left(9, 20));
  CHECK_THROWS(int_to_tree.add_right(5, 7));
  CHECK_THROWS(int_to_tree.add_right(8, 3));

  // Build tree
  CHECK_NOTHROW(int_to_tree.add_root(10));
  CHECK_NOTHROW(int_to_tree.add_left(10, 11));
  CHECK_NOTHROW(int_to_tree.add_left(11, 12));
  CHECK_NOTHROW(int_to_tree.add_right(11, 13));
  CHECK_NOTHROW(int_to_tree.add_left(13, 14));
  CHECK_NOTHROW(int_to_tree.add_right(13, 15));
  CHECK_NOTHROW(int_to_tree.add_right(10, 16));
  CHECK_NOTHROW(int_to_tree.add_right(16, 17));
  CHECK_NOTHROW(int_to_tree.add_left(17, 18));

  array<int, 9> preorder_arr{10, 11, 12, 13, 14, 15, 16, 17, 18};
  unsigned long i = 0;
  for (auto it = int_to_tree.begin_preorder(); it != int_to_tree.end_preorder(); ++it)
  {
    CHECK(*it == preorder_arr.at(i++));
  }

  array<int, 9> inorder_arr{12, 11, 14, 13, 15, 10, 16, 18, 17};
  i = 0;
  for (auto it = int_to_tree.begin_inorder(); it != int_to_tree.begin_inorder(); ++it)
  {
    CHECK(*it == inorder_arr.at(i++));
  }

  array<int, 9> postorder_arr{12, 14, 15, 13, 11, 18, 17, 16, 10};
  i = 0;
  for (auto it = int_to_tree.begin_postorder(); it != int_to_tree.begin_postorder(); ++it)
  {
    CHECK(*it == postorder_arr.at(i++));
  }
}

  TEST_CASE("Test string")
{
  BinaryTree<string> string_to_tree;
  // before add root (throw exepction)
  CHECK_THROWS(string_to_tree.add_left("a", "b"));
  CHECK_THROWS(string_to_tree.add_right("c", "d"));
  CHECK_THROWS(string_to_tree.add_right("e", "f"));

  // Build tree
  CHECK_NOTHROW(string_to_tree.add_root("a"));
  CHECK_NOTHROW(string_to_tree.add_left("a", "b"));
  CHECK_NOTHROW(string_to_tree.add_left("b", "c"));
  CHECK_NOTHROW(string_to_tree.add_right("b", "d"));
  CHECK_NOTHROW(string_to_tree.add_left("d", "e"));
  CHECK_NOTHROW(string_to_tree.add_right("d", "f"));
  CHECK_NOTHROW(string_to_tree.add_right("a", "g"));
  CHECK_NOTHROW(string_to_tree.add_right("g", "h"));
  CHECK_NOTHROW(string_to_tree.add_left("h", "i"));

  array<string, 9> preorder_arr{"a", "b", "c", "d", "e", "f", "g", "h", "i"};
  unsigned long i = 0;
  for (auto it = string_to_tree.begin_preorder(); it != string_to_tree.end_preorder(); ++it)
  {
    CHECK(*it == preorder_arr.at(i++));
  }

  array<string, 9> inorder_arr{"c", "b", "e", "d", "f", "a", "g", "i", "h"};
  i = 0;
  for (auto it = string_to_tree.begin_inorder(); it != string_to_tree.begin_inorder(); ++it)
  {
    CHECK(*it == inorder_arr.at(i++));
  }

  array<string, 9> postorder_arr{"c", "e", "f", "d", "b", "i", "h", "g", "a"};
  i = 0;
  for (auto it = string_to_tree.begin_postorder(); it != string_to_tree.begin_postorder(); ++it)
  {
    CHECK(*it == postorder_arr.at(i++));
  }
}