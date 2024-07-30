#pragma once

#include "LinkedList.hpp"

template<typename T>
class Queue
{
private:
LinkedList<T>* queue;

public:
Queue(){ this->queue = new LinkedList<T>; }
~Queue(){ delete queue; queue = nullptr; }

void peek() const;
void enqueue(T value){ this->queue->AddTail(value); }
void dequeue(){ this->queue->RemoveHead();}
bool find(T value){ return this->queue->Find(value); }
void print_queue(){ this->queue->PrintList(); }

};

template<typename T>
void Queue<T>::peek() const {
  LinkedNode<T> *node = this->queue->GetHead();
  if(node != nullptr){
    std::cout << "Next in queue: " << 
    node->GetData() << std::endl;
  }
}
