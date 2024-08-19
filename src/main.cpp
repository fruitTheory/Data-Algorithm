#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Trie trie;
  trie.Insert("Wordless");
  trie.Insert("Word");
  trie.Insert("Wor");
  trie.Insert("Worn");
  trie.Insert("Woke");
  trie.Insert("Work");
  trie.Insert("Wok");
  trie.Insert("Wo");
  trie.Insert("W");
  // trie.DeleteWord("W");

  
  
  trie.MatchPrefix("Wo");

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}