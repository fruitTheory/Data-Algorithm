#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Heap<int> heap;
  heap.Insert(10);
  heap.Insert(20);
  heap.Insert(30);
  heap.Insert(40);
  heap.Insert(50);

  heap.PrintHeap();
  heap.ExtractMax();
  heap.PrintHeap();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}