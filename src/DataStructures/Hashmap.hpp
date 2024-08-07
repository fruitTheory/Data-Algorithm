#pragma once

#include <iostream>
#include <string>

using std::string;

class Hashmap{
private:
int map[1024]{0};
unsigned int MakeHash(string key);

public:
void Insert(string key, int value);
int Get(string key);
};

void Hashmap::Insert(string key, int value){
  unsigned int hash = MakeHash(key);
  map[hash] = value;
}

int Hashmap::Get(string key){
  unsigned int hash = MakeHash(key);
  int value = map[hash];
  return value;
}

unsigned int Hashmap::MakeHash(string key){

  unsigned int hash{6546};
  for(char c : key){ hash = (hash << 3) + hash + (int)c; }
  hash &= 0b001111111111; // clip to 1 mb

  try{ if(hash > 1023){ throw "ERROR: Hash value out of index"; }}
  catch(const char* msg){ std::cerr << msg << '\n'; abort(); }
  
  return hash;
}