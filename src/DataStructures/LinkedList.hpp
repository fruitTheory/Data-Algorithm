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

  int GetSize(){ return this->size; }
  void AddHead(T data);
  void AddTail(T data);
  void InsertBefore(T data, T input, bool all=false);
  void InsertAfter(T data, T input, bool all=false);
  void PrintList();

};

template<typename T>
void LinkedList<T>::AddHead(T data){
  head = new Node(data, head);
  // Set tail to head if empty
  if(tail == nullptr)
  {tail = head;}
  this->size++;
}

template<typename T>
void LinkedList<T>::AddTail(T data){
  Node<T> *NewNode = new Node(data);

  if(head == nullptr){
    head = NewNode;
    tail = NewNode;
  } else{
    tail->SetNextPtr(NewNode);
    tail = NewNode;
  }
  this->size++;
}

template<typename T>
void LinkedList<T>::InsertBefore(T data, T input, bool all){

  if(this->size == 0){ return; }

  Node<T> *current = head;
  Node<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();

    if(previous->GetData() == input){
      head = new Node(data, head);
      break;
    }

    if(current->GetData() == input){
      Node<T> *NewNode = new Node(data);
      previous->SetNextPtr(NewNode);
      NewNode->SetNextPtr(current);
      break;
    }
  }

  this->size++;
}

template<typename T>
void LinkedList<T>::InsertAfter(T data, T input, bool all){

  if(this->size == 0){ return; }

  Node<T> *current = head;
  Node<T> *previous = nullptr;
  Node<T> *next = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();

    // Case for head
    if(previous->GetData() == input){
      Node<T> *NewNode = new Node(data);
      previous->SetNextPtr(NewNode);
      NewNode->SetNextPtr(current);
      break;
    }
    
    if(current->GetData() == input){
      Node<T> *NewNode = new Node(data);
      next = current->GetNextPtr();
      NewNode->SetNextPtr(next);
      current->SetNextPtr(NewNode);
      break;
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