#pragma once

#include <iostream>

template<typename T>
class LinkedNode{
private:
T data;
LinkedNode<T> *next;

public:
LinkedNode(T data, LinkedNode *next=nullptr){
  this->data = data;
  this->next = next;
}
T GetData() const { return this->data; }
LinkedNode<T>* GetNextPtr() const { return this->next; }
void SetNextPtr(LinkedNode<T>* next){ this->next = next; }
};

template<typename T>
class LinkedList{
private:
LinkedNode<T> *head;
LinkedNode<T> *tail;
size_t size;

public:
int GetSize(){ return this->size; }
LinkedNode<T>* GetHead(){ return this->head; }
LinkedNode<T>* GetTail(){ return this->tail; }

public:
LinkedList(){
  this->head = nullptr;
  this->tail = nullptr;
  this->size = 0;
}
~LinkedList();
LinkedList(const LinkedList<T> &list);
LinkedList &operator=(const LinkedList<T> &list);
LinkedList(LinkedList<T> &&list) noexcept;
LinkedList &operator=(LinkedList<T> &&list) noexcept;

void AddHead(T data);
void AddTail(T data);
void RemoveHead();
void RemoveTail();
void Remove(T input);
bool Find(T input);
void InsertBefore(T input, T data, bool all=false);
void InsertAfter(T input, T data, bool all=false);
void PrintList();

};

template<typename T>
void LinkedList<T>::AddHead(T data){
  head = new LinkedNode<T>(data, head);
  if(tail == nullptr)
  {tail = head;}
  this->size++;
}

template<typename T>
void LinkedList<T>::AddTail(T data){
  LinkedNode<T> *NewNode = new LinkedNode<T>(data);
  if(head == nullptr){
    head = NewNode;
    tail = NewNode;
    this->size++;
    return;
  } 
  LinkedNode<T> *current = head;
  LinkedNode<T> *previous = nullptr;

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

  LinkedNode<T> *current = list.head;
  head = nullptr;
  tail = nullptr;
  while(current != nullptr){
    LinkedNode<T>* node = new LinkedNode<T>(current->GetData());

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

    LinkedNode<T> *current = list.head;
    head = nullptr;
    tail = nullptr;
    while(current != nullptr){
      LinkedNode<T>* node = new LinkedNode<T>(current->GetData());

      if(head == nullptr){ AddHead(node->GetData()); }
      else{ AddTail(node->GetData()); }
      
      current = current->GetNextPtr();
    }
    size = list.size;

  }
  return *this;
}

template<typename T>
LinkedList<T>::LinkedList(LinkedList<T> &&list) noexcept{
  this->head = list.head;
  this->tail = list.tail;
  this->size = list.size;

  list.head = nullptr;
  list.tail = nullptr;
  list.size = 0;
}

template<typename T>
LinkedList<T>& LinkedList<T>::operator=(LinkedList<T> &&list) noexcept{
  if(this != &list){
    this->head = list.head;
    this->tail = list.tail;
    this->size = list.size;

    list.head = nullptr;
    list.tail = nullptr;
    list.size = 0;
  }
  return *this;
}

template<typename T>
void LinkedList<T>::RemoveHead(){

  if(this->size == 0){ return; }

  LinkedNode<T> *OldHead = head;
  head = head->GetNextPtr();
  delete OldHead;
  OldHead = nullptr;

  this->size--;
}

template<typename T>
void LinkedList<T>::RemoveTail(){

  if(this->size == 0){ return; }
  if(this->size == 1){ RemoveHead(); return;}

  LinkedNode<T> *current = head;
  LinkedNode<T> *previous = nullptr;

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

  LinkedNode<T> *current = head;
  LinkedNode<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();
    if(current != nullptr && current->GetData() == input){
      LinkedNode<T> *Tnext = current->GetNextPtr();
      previous->SetNextPtr(Tnext);
      delete current;
      current = nullptr;
    } else if(current == nullptr){
      std::cerr << "Error: Remove value not found." << std::endl;
      return;
    }
  }
  this->size--;
}

template<typename T>
bool LinkedList<T>::Find(T input){

  LinkedNode<T> *current = head;
  LinkedNode<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();
    if(previous->GetData() == input){
      return true;
    }
  } return false;
}

template<typename T>
void LinkedList<T>::InsertBefore(T input, T data, bool all){

  if(this->size == 0){ return; }

  LinkedNode<T> *current = head;
  LinkedNode<T> *previous = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();

    if(previous->GetData() == input){
      head = new LinkedNode<T>(data, head);
      break;
    }

    if(current != nullptr && current->GetData() == input){
      LinkedNode<T> *NewNode = new LinkedNode<T>(data);
      previous->SetNextPtr(NewNode);
      NewNode->SetNextPtr(current);
      break;
    } else if(current == nullptr){
      std::cerr << "Error: Insert value not found." << std::endl;
      return;
    }
  }
  this->size++;
}

template<typename T>
void LinkedList<T>::InsertAfter(T input, T data, bool all){

  if(this->size == 0){ return; }

  LinkedNode<T> *current = head;
  LinkedNode<T> *previous = nullptr;
  LinkedNode<T> *next = nullptr;

  while(current != nullptr){
    previous = current;
    current = current->GetNextPtr();

    // Case for head
    if(previous->GetData() == input){
      LinkedNode<T> *NewNode = new LinkedNode<T>(data);
      previous->SetNextPtr(NewNode);
      NewNode->SetNextPtr(current);
      break;
    }
    
    if(current != nullptr && current->GetData() == input){
      LinkedNode<T> *NewNode = new LinkedNode<T>(data);
      next = current->GetNextPtr();
      NewNode->SetNextPtr(next);
      current->SetNextPtr(NewNode);
      if(next == nullptr){
        tail = NewNode;
      }
      break;
    } else if(current == nullptr){
      std::cerr << "Error: Insert value not found." << std::endl;
      return;
    }
  }
  this->size++;
}

template<typename T>
void LinkedList<T>::PrintList(){
  LinkedNode<T> *current = head;
  while(current != nullptr){
    T data = current->GetData();
    std::cout << data << "\n";
    current = current->GetNextPtr();
  }
}

template<typename T>
LinkedList<T>::~LinkedList(){
  LinkedNode<T> *current = head;
  while(current != nullptr){
    LinkedNode<T> *previous = current;
    current = current->GetNextPtr();
    delete previous;
    previous = nullptr;
  }
}