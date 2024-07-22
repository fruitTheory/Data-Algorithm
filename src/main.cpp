#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Stack<int> stack = {1, 2 ,3};
  stack.print_stack();
  stack.pop();
  stack.push(6);
  stack.push(8);
  stack.push(10);
  stack.print_stack();

  Stack<int> stack2;
  stack2.push(40);stack2.push(50);stack2.push(60);
  stack2.print_stack();
  stack2.pop(); stack2.print_stack();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}