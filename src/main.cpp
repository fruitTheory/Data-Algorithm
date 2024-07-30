#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  // BinarySearchTree<int> tree;
  // tree.Insert(45);

  LinkedList<int> list;
  list.AddHead(40);
  list.GetHead();
  list.PrintList();
  list.Remove(20);
  list.InsertBefore(20, 20);

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}