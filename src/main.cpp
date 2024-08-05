#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  BinarySearchTree<int> tree;
  tree.Insert(45);
  tree.Insert(40);
  tree.Insert(55);
  tree.Insert(42);
  tree.Insert(44);
  tree.Insert(50);
  tree.Insert(57);
  tree.Insert(48);

  tree.Remove(40);
  tree.Remove(42);
  tree.Remove(48);
  tree.Remove(57);

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}