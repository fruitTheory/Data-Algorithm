#pragma once

#include <iostream>
#include <vector>
#include <cmath>

using std::vector;

template<typename T>
class Heap
{
private:
vector<T> heap;

public:
Heap(){}
~Heap(){}

void Insert(T value);
void ExtractMax();
void BubbleUp(int index);
void BubbleDown(int index);
int GetMax(){ return heap[0]; }
size_t GetSize(){ return heap.size(); }
double GetParentIndex(int index){ return floor((index-1)/2); }
inline int GetChildLeft(int index){ return 2 * index + 1; }
inline int GetChildRight(int index){ return 2 * index + 2; }
void PrintHeap(){ for(int value:this->heap){std::cout << value << " ";} std::cout << std::endl; }
};

template<typename T>
void Heap<T>::Insert(T value){
  this->heap.push_back(value);
  BubbleUp(GetSize()-1);
}

  // Bubble up most recent value
template<typename T>
void Heap<T>::BubbleUp(int index){

  if(index == 0){ return; }

  auto ParentIndex = GetParentIndex(index);
  int NewValue = this->heap[index];
  int ParentValue = this->heap[ParentIndex];

  // If new value is greater swap with parent
  if(NewValue > ParentValue){
    this->heap[ParentIndex] = NewValue;
    this->heap[index] = ParentValue;
    BubbleUp(ParentIndex);
  }
}

template<typename T>
void Heap<T>::ExtractMax(){
  if(GetSize() == 0){ std::cout << "Heap Empty" << std::endl; return; }
  if(GetSize() == 1){ this->heap.pop_back(); return; }

  // Replace max with last elem
  int end = this->heap[GetSize()-1];
  this->heap.pop_back();
  this->heap[0] = end;

  BubbleDown(0);
}

template<typename T>
void Heap<T>::BubbleDown(int index){

  int left_index = GetChildLeft(index);
  int right_index = GetChildRight(index);
  int top_index = index;

  if(left_index < GetSize() &&
  this->heap[left_index] > this->heap[top_index]){
    top_index = left_index;  
  }

  if(right_index < GetSize() &&
  this->heap[right_index] > this->heap[top_index]){
    top_index = right_index;  
  }

  if(top_index != index){
    int previous_top = this->heap[index];
    this->heap[index] = this->heap[top_index];
    this->heap[top_index] = previous_top;
    BubbleDown(top_index);
  }
}