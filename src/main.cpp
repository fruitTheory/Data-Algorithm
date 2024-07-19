#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  DynamicArray<int> arr;
  arr.push_back(60);
  arr.push_back(40);
  arr.push_back(20);
  arr.pop_back();
  arr.push_back(80);
  arr.print_arr();
  
  LinkedList<int> list;
  list.AddHead(60);
  list.AddHead(40);
  list.AddHead(20);
  list.PrintList();

  LinkedList<int> list2 = list;
  list2.PrintList();

  LinkedList<int> list3;
  list3.AddHead(100);
  list3.AddHead(200);
  list3 = list2;

  LinkedList<int> list4 = std::move(list2);
  list4.PrintList();
  list3 = std::move(list4);

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}