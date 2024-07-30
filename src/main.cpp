#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  BinarySearchTree<int> tree;
  tree.Insert(45);
  tree.Insert(40);

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}