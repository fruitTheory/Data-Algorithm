#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  LinkedList<int> list;

  list.AddHead(20);
  list.InsertBefore(20, 40);
  list.InsertAfter(20, 40);
  list.AddTail(90);
  list.InsertBefore(90, 50);
  list.InsertAfter(90, 40);

  list.Remove(90);
  list.AddTail(200);


  list.PrintList();
  print(list.GetSize());  


  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}