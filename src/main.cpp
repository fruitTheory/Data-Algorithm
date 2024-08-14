#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Trie trie;
  trie.Insert("Word");
  trie.Insert("Wont");
  trie.Insert("Test");
  std::cout << trie.FindWord("Wont") << std::endl;
  trie.DeleteWord("Wont");
  std::cout << trie.FindWord("Wont") << std::endl;

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}