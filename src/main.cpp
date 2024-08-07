#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Hashmap map;
  map.Insert("Key", 54389);
  int value = map.Get("Key");
  print(value);

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}