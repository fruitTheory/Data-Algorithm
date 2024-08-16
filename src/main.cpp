#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Trie trie;
  trie.Insert("Wordless");
  trie.Insert("Word");
  trie.Insert("Worm");
  trie.Insert("Wont");
  trie.Insert("Test");

  trie.MatchPrefix("Wo");

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}