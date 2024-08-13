#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Trie trie;
  trie.Insert("Word");
  trie.Insert("Wont");
  trie.Insert("Test");
  trie.FindWord("eek");
  trie.DeleteWord("wont");

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}