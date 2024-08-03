#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  BinarySearchTree<int> tree;
  tree.Insert(45);
  tree.Insert(40);
  tree.Insert(35);
  tree.Insert(55);
  tree.Insert(48);
  tree.Insert(50);
  tree.Remove(45);

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}