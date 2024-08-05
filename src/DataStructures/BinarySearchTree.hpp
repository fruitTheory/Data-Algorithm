#pragma once

#include <memory>

using std::unique_ptr;
using std::make_unique;

template<typename T>
class BST_Node{
private:
T data;
unique_ptr<BST_Node<T>> left;
unique_ptr<BST_Node<T>> right;

public:
unique_ptr<BST_Node<T>> GetLeft(){ return std::move(this->left); }
unique_ptr<BST_Node<T>> GetRight(){ return std::move(this->right); }

public:
BST_Node():data(0){}
BST_Node(T data){ this->data = data; }

void SetData(T data){ this->data = data; }
T GetData() const{ return this->data; }

void SetLeft(unique_ptr<BST_Node<T>> &left){ this->left = std::move(left); }
void SetRight(unique_ptr<BST_Node<T>> &right){ this->right = std::move(right); }
void ClearLeft(){ this->left = nullptr; }

BST_Node<T>* GetLeftPtr(){ return this->left.get(); }
BST_Node<T>* GetRightPtr(){ return this->right.get(); }
};

template<typename T>
class BinarySearchTree{
private:
unique_ptr<BST_Node<T>> root;

public:
BinarySearchTree() = default;
~BinarySearchTree() = default;
void Insert(T data);
void Remove(T data);
unique_ptr<BST_Node<T>> GetSingleChild(BST_Node<T> *node);
int CountChildren(BST_Node<T> *node);
int WhichEdge(BST_Node<T> *node);
};

template<typename T>
unique_ptr<BST_Node<T>> BinarySearchTree<T>::GetSingleChild(BST_Node<T> *node){
  if(node->GetLeftPtr() != nullptr){ return node->GetLeft(); }
  else{ return node->GetRight(); }
}

// Which child exists, 0 for left 1 for right
template<typename T>
int BinarySearchTree<T>::WhichEdge(BST_Node<T> *node){
  if(node->GetLeftPtr() != nullptr){ return 0; }
  else{ return 1; }
}

template<typename T>
int BinarySearchTree<T>::CountChildren(BST_Node<T> *node){
  int child_count = 0;
  if(node->GetLeftPtr() != nullptr){ ++child_count; }
  if(node->GetRightPtr() != nullptr){ ++child_count; }
  return child_count;
}

template<typename T>
void BinarySearchTree<T>::Remove(T data){

  BST_Node<T>* current = this->root.get();
  BST_Node<T>* previous = nullptr;

  if(data == current->GetData()){ 
    std::cout << "Root removal not implemented" << std::endl;
    // this->root = current->GetLeft();
    return;
  }

  int _switch = 0;
  while(true){
    if(data < current->GetData() || (_switch == 0 && data == current->GetData())){
      if(data == current->GetData()){
        int child_count = CountChildren(current);
        switch(child_count)
        {
        case 0:{
          previous->GetLeft().reset();
          break;
        }
        case 1:{
          unique_ptr<BST_Node<T>> child = GetSingleChild(current);
          previous->SetLeft(child);
          break;
        }
        case 2:{
          break;
        }
        default:
          std::cerr << "Child count out of range" << std::endl;
          break;
        }
        return;
      }
      previous = current;
      current = current->GetLeftPtr();
      _switch = 0;
    }

    else if(data > current->GetData() || (_switch == 1 && data == current->GetData())){
      if(data == current->GetData()){
        int child_count = CountChildren(current);
        switch(child_count)
        {
        case 0:{
          previous->GetRight().reset();
          break;
        }
        case 1:{
          unique_ptr<BST_Node<T>> child = GetSingleChild(current);
          previous->SetRight(child);
          break;
        }
        case 2:{
          break;
        }
        default:
          std::cerr << "Child count out of range" << std::endl;
          break;
        }
        return;
      }
      previous = current;
      current = current->GetRightPtr();
      _switch = 1;
    }
  }

}

template<typename T>
void BinarySearchTree<T>::Insert(T data){

  if(this->root == nullptr){
    this->root = make_unique<BST_Node<T>>(data);
    return;
  }

  BST_Node<T>* current = this->root.get();

  /*
  // If value is less than current go left else go right
  // If path node doesnt exist make new and set path
  // If path node does exist update to current and cmp value again
  */
 
  while(true){
    if(data < current->GetData()){
      if(current->GetLeftPtr() == nullptr){
        unique_ptr<BST_Node<T>> node = make_unique<BST_Node<T>>(data);
        current->SetLeft(node);
        return;
      } else{ current = current->GetLeftPtr(); }
    } 
    else if(data > current->GetData()){
      if(current->GetRightPtr() == nullptr){
        unique_ptr<BST_Node<T>> node = make_unique<BST_Node<T>>(data);
        current->SetRight(node);
        return;
      } else{ current = current->GetRightPtr(); }
    }
  }
}
