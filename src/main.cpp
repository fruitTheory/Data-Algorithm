#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Trie trie;
  trie.Insert("Word");
  trie.Insert("Wor");
  trie.Insert("Wok");
  trie.Insert("Wo");
  trie.Insert("W");

  // std::cout << trie.FindWord("W") << std::endl;
  trie.DeleteWord("W");
  // std::cout << trie.FindWord("W") << std::endl;

  trie.MatchPrefix("Wo");

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}