#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  LinkedList<int> list;

  list.AddHead(20);
  list.AddTail(60);
  list.AddTail(40);
  list.AddTail(90);
  list.InsertBefore(100, 20);

  list.PrintList();
  print(list.GetSize());  


  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}