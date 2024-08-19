#pragma once

#include <iostream>
#include <unordered_map>
#include <memory>
#include <vector>

class TrieNode;
using std::string;
using std::unordered_map;
using std::unique_ptr;
using std::make_unique;
using std::vector;
using HASHMAP = unordered_map<char, unique_ptr<TrieNode>>;

class TrieNode{
private:
HASHMAP child_property;
bool EndOfWord{false};

public:
bool isEndOfWord(){ return this->EndOfWord; }
void setEndOfWord(bool status){ this->EndOfWord = status; }
void SetProperty(char key, unique_ptr<TrieNode> node){ child_property.emplace(key, std::move(node)); }
[[nodiscard]]TrieNode* GetChild(char key){ return child_property[key].get(); }
size_t GetSize(){ return child_property.size(); }
void DeleteNode(char key){ child_property.erase(key); }
bool KeyExists(char key){ int x = child_property.count(key); return x > 0 ? true:false; }
[[nodiscard]]char GetKey(){ return child_property.size()>0 ? child_property.begin()->first : ' '; }
[[nodiscard]]vector<char> GetKeys();
};

class Trie{
private:
unique_ptr<TrieNode> root;

protected:
bool hasPrefix(string word);
void Lowercase(string &word){ for(char& c:word){c = tolower(c); }}
int WordAmount(char key, TrieNode* current);
void GetPrefixed(TrieNode* current, string &stem, vector<string> &stems, string &prefix);

public:
Trie(){ this->root = make_unique<TrieNode>(); }
void Insert(string word);
bool FindWord(string word);
vector<string> MatchPrefix(string prefix);
void DeleteWord(string word);
void PrintWords(vector<string> words);
};

// Insert a word into Trie
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

// Find if a word exists in Trie
bool Trie::FindWord(string word){
  Lowercase(word);
  TrieNode* current = this->root.get();

  for(size_t x = 0; x < word.size(); x++){
    if(current->KeyExists(word[x])){
      // Check if end of word on last loop
      if(x == word.size()-1 &&
        current->isEndOfWord()){ return true; }
      current = current->GetChild(word[x]); 
    } else{ return false; }
  }
  return false; 
}

// Delete a word from Trie
void Trie::DeleteWord(string word){
  Lowercase(word);
  if(!FindWord(word)){
    std::cout << "DeleteWord: Word doesn't exist!" << std::endl;
    return; }
  bool prefixed = hasPrefix(word);

  TrieNode* current = this->root.get();
  TrieNode* current_prefixed{current};
  int current_EOW{0};

  // If no prefixes or embedded words can delete, handles one letter case
  if(!prefixed && word.size() > 1){
    current->DeleteNode(word[0]);
    return;
  } else if(!prefixed && word.size() == 1){
    current->setEndOfWord(false);
    return;
  }
  for(size_t x = 0; x < word.size(); x++){
    // Case to delete child nodes if its last word in line
    if(current->isEndOfWord() && current->GetChild(word[x])->GetSize() == 0){
      current_prefixed->GetChild(word[current_EOW])->DeleteNode(word[current_EOW+1]);
      return;
    }
    // Before overlapping after end of word statement
    if(current->isEndOfWord()){
      current_prefixed = current;
      current_EOW = x;
    }
    // Case if end of word but has size beyond
    if(current->isEndOfWord() && x == word.size()-1){
      current_prefixed->setEndOfWord(false);
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

// Get amount of words from a prefix *Not fully working
int Trie::WordAmount(char key, TrieNode* current){
  int word_amount{0};
  while(current != nullptr){
    if(current->GetSize() > 1){
      vector<char> keys = current->GetKeys();
      for(char key: keys){
        TrieNode* temp = current->GetChild(key);
        if(temp->isEndOfWord()){
          ++word_amount; }
      }
    } else if(current->isEndOfWord()){ ++word_amount; }

    if(current->GetSize() != 0){
      current = current->GetChild(key);
    } else{ break; }

    if(current->GetKey() != ' ')
      key = current->GetKey();
    } 
  return word_amount;
}

// Emplaces prefixed words starting at current ptr
void Trie::GetPrefixed(TrieNode* current, string &stem, vector<string> &stems, string &prefix){
  if(current->GetSize() == 0){ return; }

  for(char key : current->GetKeys()){
    // std::cout << "Key: " << key << std::endl;
    stem.push_back(key);
    if(current->isEndOfWord()){ stems.emplace_back(prefix+stem); }
    GetPrefixed(current->GetChild(key), stem, stems, prefix);
    stem.pop_back();
  }
}

// Return a vector of words that match prefix
vector<string> Trie::MatchPrefix(string prefix){
  Lowercase(prefix);
  TrieNode* current = this->root.get();

  // Set node to end of prefix
  for(size_t x = 0; x < prefix.size(); x++){
    current = current->GetChild(prefix[x]); }
  
  string stem;
  vector<string> stems;
  GetPrefixed(current, stem, stems, prefix);

  for(string stem: stems){
    std::cout << stem << std::endl;
  }
  return stems;
}

// Determine if a word has embedded words or split paths
bool Trie::hasPrefix(string word){
  Lowercase(word);
  TrieNode* current = this->root.get();
  int word_amount = WordAmount(word[0], current);

  for(size_t x = 0; x < word.size(); x++){
    if(current->KeyExists(word[x])){
      if(current->GetSize() > 1 || word_amount > 1 && x != 0){
        return true;
      }
      current = current->GetChild(word[x]); 
    }
  } return false;
}

// Provide vector of words such as from MatchPrefix()
void Trie::PrintWords(vector<string> words){
  for(auto word: words){
    std::cout << word << std::endl;
  }
}
