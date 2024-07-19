#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  DynamicArray<int> arr;
  arr.push_back(60);
  arr.get_size();
  

  LinkedList<int> list;
  list.AddTail(40);
  list.AddHead(60);
  list.InsertAfter(40, 90);
  list.PrintList();

  LinkedList<int> list2 = list;
  list2.PrintList();
  print(list2.GetSize());

  // LinkedList<int> list3;
  // list3 = list2;
  // list3.PrintList();
  

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}