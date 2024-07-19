#pragma once

#include <iostream>
#include "utility.hpp"

template<typename T>
class Node{
private:
  T data;
  Node<T> *next;

public:
  Node(T data, Node *next=nullptr){
    this->data = data;
    this->next = next;
  }

  T GetData() const {
    return data;
  }

  Node<T>* GetNextPtr() const {
    return next;
  }

  void SetNextPtr(Node<T>* next){
    this->next = next;
  }

};

template<typename T>
class LinkedList{
private:
  Node<T> *head;
  Node<T> *tail;
  size_t size;

public:
  LinkedList(){
    this->head = nullptr;
    this->tail = nullptr;
    this->size = 0;
  }
  ~LinkedList();
  LinkedList(const LinkedList<T> &list);
  LinkedList &operator=(const LinkedList<T> &list);

  int GetSize(){ return this->size; }
  void AddHead(T data);
  void AddTail(T data);
  void RemoveHead();
  void RemoveTail();
  void Remove(T input);
  void InsertBefore(T input, T data, bool all=false);
  void InsertAfter(T input, T data, bool all=false);
  void PrintList();

};

template<typename T>
void LinkedList<T>::AddHead(T data){
  head = new Node<T>(data, head);
  if(tail == nullptr)
  {tail = head;}
  this->size++;
}

template<typename T>
void LinkedList<T>::AddTail(T data){
  Node<T> *NewNode = new Node<T>(data);
  if(head == nullptr){
    head = NewNode;
    tail = NewNode;
    this->size++;
    return;
  } 
  Node<T> *current = head;
  Node<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();
    if(current == nullptr){
      tail = NewNode;
      previous->SetNextPtr(NewNode);
    }
  }
  this->size++;
}

template<typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list){

  Node<T> *current = list.head;
  head = nullptr;
  tail = nullptr;
  while(current != nullptr){
    Node<T>* node = new Node<T>(current->GetData());

    if(head == nullptr){
      AddHead(node->GetData());
    } else{
      AddTail(node->GetData());
    }
    current = current->GetNextPtr();
  }
  size = list.size;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(const LinkedList<T> &list){

  if(this != &list){
    // Cleanup
    while(this->head != nullptr){
      RemoveHead();
    }
    
    Node<T> *current = list.head;
    head = nullptr;
    tail = nullptr;
    while(current != nullptr){
      Node<T>* node = new Node<T>(current->GetData());

      if(head == nullptr){
        AddHead(node->GetData());
      } else{
        AddTail(node->GetData());
      }
      current = current->GetNextPtr();
    }
    size = list.size;

  }
  return *this;
}

template<typename T>
void LinkedList<T>::RemoveHead(){

  if(this->size == 0){ return; }

  Node<T> *OldHead = head;
  head = head->GetNextPtr();
  delete OldHead;
  OldHead = nullptr;

  this->size--;
}

template<typename T>
void LinkedList<T>::RemoveTail(){

  if(this->size == 0){ return; }
  if(this->size == 1){ RemoveHead(); return;}

  Node<T> *current = head;
  Node<T> *previous = nullptr;

  // Reaching end of list
  while(current->GetNextPtr() != nullptr){
    previous = current;
    current = current->GetNextPtr();
  }

  // Disconnects tail
  previous->SetNextPtr(nullptr);
  delete current;
  current = nullptr;
  tail = previous;

  this->size--;
}

template<typename T>
void LinkedList<T>::Remove(T input){

  if(this->size == 0){ return; }
  if(head->GetData() == input){
    RemoveHead();
    return;
  } 

  Node<T> *current = head;
  Node<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();
    if(current->GetData() == input){
      Node<T> *Tnext = current->GetNextPtr();
      previous->SetNextPtr(Tnext);
      delete current;
      current = nullptr;
    } else if(current->GetNextPtr() == nullptr){
      std::cerr << "Error: Remove value not found." << std::endl;
      return;
    }
  }

  this->size--;
}

template<typename T>
void LinkedList<T>::InsertBefore(T input, T data, bool all){

  if(this->size == 0){ return; }

  Node<T> *current = head;
  Node<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();

    if(previous->GetData() == input){
      head = new Node<T>(data, head);
      break;
    }

    if(current->GetData() == input){
      Node<T> *NewNode = new Node<T>(data);
      previous->SetNextPtr(NewNode);
      NewNode->SetNextPtr(current);
      break;
    } else if(current->GetNextPtr() == nullptr){
      std::cerr << "Error: Insert value not found." << std::endl;
      return;
    }
  }
  this->size++;
}

template<typename T>
void LinkedList<T>::InsertAfter(T input, T data, bool all){

  if(this->size == 0){ return; }

  Node<T> *current = head;
  Node<T> *previous = nullptr;
  Node<T> *next = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();

    // Case for head
    if(previous->GetData() == input){
      Node<T> *NewNode = new Node<T>(data);
      previous->SetNextPtr(NewNode);
      NewNode->SetNextPtr(current);
      break;
    }
    
    if(current->GetData() == input){
      Node<T> *NewNode = new Node<T>(data);
      next = current->GetNextPtr();
      NewNode->SetNextPtr(next);
      current->SetNextPtr(NewNode);
      if(next == nullptr){
        tail = NewNode;
      }
      break;
    } else if(current->GetNextPtr() == nullptr){
      std::cerr << "Error: Insert value not found." << std::endl;
      return;
    }
  }
  this->size++;
}

template<typename T>
void LinkedList<T>::PrintList(){
  Node<T> *current = head;
  while(current != nullptr){
    T data = current->GetData();
    std::cout << data << "\n";
    current = current->GetNextPtr();
  }
}

template<typename T>
LinkedList<T>::~LinkedList(){
  Node<T> *current = head;
  while(current != nullptr){
    Node<T> *previous = current;
    current = current->GetNextPtr();
    delete previous;
    previous = nullptr;
  }
}