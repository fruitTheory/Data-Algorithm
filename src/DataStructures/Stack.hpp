#pragma once

#include <iostream>
using std::initializer_list;

template<typename T>
class Stack{
private:
T *data;
size_t size;
size_t capacity;

protected:
T* get_data() const { return this->data; }
size_t get_capacity() const { return this->capacity; }

public:
Stack(size_t capacity=10):capacity(capacity), size(0), data(new T[capacity]){}
Stack(initializer_list<T> init_list);
~Stack(){ delete[] data; }

void pop(){ if(size > 0){--this->size;} };
void push(T value);
void peek(){ if(size > 0){ std::cout << data[this->size-1] << "\n"; } }
size_t get_size() const { return this->size; }
void print_stack();

};

template<typename T>
Stack<T>::Stack(initializer_list<T> init_list): size(0){
  size_t list_size = init_list.size();
  capacity = list_size;
  data = new T[capacity];
  for(const T value : init_list){ data[size++] = value; }
}

template<typename T>
void Stack<T>::print_stack(){
  if(this->size > 0){
    for(int x = 0; x < this->size; x++){
      std::cout << data[x] << " ";
    } std::cout << std::endl;
  }
}

template<typename T>
void Stack<T>::push(T value){
  if(this->size == capacity){
    capacity *= 2;
    T* resized = new T[capacity];
    for(int x = 0; x < this->size; x++){
      resized[x] = data[x];
    }
    data = resized;
    data[this->size++] = value;
  } else{
    data[this->size++] = value;
  }
}