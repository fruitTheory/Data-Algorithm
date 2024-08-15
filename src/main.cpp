#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Trie trie;
  trie.Insert("Wordless");
  // std::cout << trie.FindWord("Wordless") << std::endl;
  trie.Insert("Word");
  trie.Insert("Wont");
  trie.Insert("Test");

  trie.MatchPrefix("Wo");

  // std::cout << trie.FindWord("Wont") << std::endl;
  // trie.DeleteWord("Wont");
  // std::cout << trie.FindWord("Wont") << std::endl;

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}