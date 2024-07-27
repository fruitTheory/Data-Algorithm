#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Queue<int> queue;
  queue.enqueue(6);
  queue.enqueue(8);
  queue.enqueue(10);
  queue.dequeue();
  queue.print_queue();
  queue.find(10);
  queue.peek();

  Stack<int> stack{ 1, 2, 3 };
  stack.peek();

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}