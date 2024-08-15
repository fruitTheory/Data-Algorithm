#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

using std::string;
using std::unordered_map;
using std::unique_ptr;
using std::make_unique;
using std::vector;

class TrieNode{
private:
unordered_map<char, unique_ptr<TrieNode>> child_property;
bool EndOfWord{false};

public:
bool isEndOfWord(){ return this->EndOfWord; }
void setEndOfWord(bool status){ this->EndOfWord = status; }
void SetProperty(char key, unique_ptr<TrieNode> node){ child_property.emplace(key, std::move(node)); }
TrieNode* GetChild(char key){ return child_property[key].get(); }
size_t GetSize(){ return child_property.size(); }
void DeleteNode(char key){ child_property.erase(key); }
bool KeyExists(char key){ int x = child_property.count(key); return x > 0 ? true:false; }
// char GetChildCharAdv(char c);
char GetKey(){ return child_property.size()>0 ? child_property.begin()->first : ' '; }
vector<char> GetKeys();
};

class Trie{
private:
unique_ptr<TrieNode> root;

protected:
bool hasPrefix(string word);
string SeekPrefixWords(char key, TrieNode* current);
void PrintPrefixes(vector<string> words);
void Lowercase(string &word){ for(char& c:word){c = tolower(c); }}

public:
Trie(){ this->root = make_unique<TrieNode>(); }
void Insert(string word);
bool FindWord(string word);
void MatchPrefix(string prefix);
void DeleteWord(string word);
void Print(string c);
};

void Trie::Insert(string word){
  Lowercase(word);
  TrieNode* current = this->root.get();

  for(size_t x = 0; x < word.size(); x++){
    if(!current->KeyExists(word[x])){
      current->SetProperty(word[x], make_unique<TrieNode>()); }

    if(x == word.size()-1){ current->setEndOfWord(true); }
    current = current->GetChild(word[x]);
  }
}

bool Trie::FindWord(string word){
  Lowercase(word);
  TrieNode* current = this->root.get();

  for(size_t x = 0; x < word.size(); x++){
    if(current->KeyExists(word[x])){
      // Check if is end of word on last loop
      if(x == word.size()-1 &&
        current->isEndOfWord()){ return true; }
      current = current->GetChild(word[x]); 
    } else{ return false; }
  }
  return false; 
}

void Trie::DeleteWord(string word){
  Lowercase(word);
  if(!FindWord(word)){ return; }
  bool prefixed = hasPrefix(word);

  TrieNode* current = this->root.get();
  TrieNode* last_prefixed{nullptr};
  int iter_prefix{0};

  for(size_t x = 0; x < word.size(); x++){
    // If not a prefix word, just delete
    if(!prefixed){
      current->DeleteNode(word[x]);
      return;
    }
    // Store node if it is the end of a prefix
    if(current->GetSize() > 1){
      last_prefixed = current;
      iter_prefix = x;
    }
    // Delete starting at last prefix split
    if(current->isEndOfWord()){
      last_prefixed->DeleteNode(word[iter_prefix]);
      return;
    }
    current = current->GetChild(word[x]);
  }
}

// Return a vector of keys from current node
vector<char> TrieNode::GetKeys(){ 
  vector<char> keys;
  for(int x = 0; x < child_property.size(); x++){
    auto it = child_property.begin();
    std::advance(it, x);
    char current = it->first;
    keys.emplace_back(current);
  } return keys;
}

string Trie::SeekPrefixWords(char key, TrieNode* current){

  TrieNode* last_prefixed{nullptr};
  int iter_prefix{0};
  string stem;
  stem.push_back(key);
  int word_amount{0};

  // Get amount of words from prefix
  // while(current != nullptr){
  //   if(current->isEndOfWord()){
  //     ++word_amount;
  //   }
  //   current = current->GetChild(key);
  // }

  // Get letters from each word
  while(current != nullptr){
    if(current->GetSize() == 1){
      key = current->GetKey();
      stem.push_back(key);
    }
    std::cout << "End: " << key << " " << current->isEndOfWord() << std::endl;
    current = current->GetChild(key);
  }

  for(char letter: stem){
    std::cout << letter;
  } print("");

  return stem;
}

// Return vector of words that match prefix
void Trie::MatchPrefix(string prefix){
  Lowercase(prefix);
  TrieNode* current = this->root.get();

  // Set to node at prefix
  for(size_t x = 0; x < prefix.size(); x++){
    current = current->GetChild(prefix[x]); }

  // Get keys at end of prefix
  vector<char> keys = current->GetKeys();

  vector<string> temp;

  // For each key seek possible words
  for(char key : keys){
    std::cout << "key: " << key << std::endl;
    string stem = SeekPrefixWords(key, current);
    temp.push_back(prefix + stem);
    break;
  }

  print(temp[0]);

}

bool Trie::hasPrefix(string word){
  Lowercase(word);
  TrieNode* current = this->root.get();
  current = current->GetChild(word[0]);

  for(size_t x = 1; x < word.size(); x++){
    if(current->KeyExists(word[x])){
      if(current->GetSize() > 1){
        return true;
      }
      current = current->GetChild(word[x]); 
    }
  }
  return false;
}

void Trie::Print(string c){
  Lowercase(c);
}

// char TrieNode::GetChildCharAdv(char c){ 
//   for(int x = 0; x < child_property.size(); x++){
//     auto it = child_property.begin();
//     std::advance(it, x);
//     char current = it->first;
//     if(current == c){ return current; }
//   } return ' ';
// }