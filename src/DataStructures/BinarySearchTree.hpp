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

protected:
unique_ptr<BST_Node<T>> GetLeft(){ return std::move(this->left); }
unique_ptr<BST_Node<T>> GetRight(){ return std::move(this->right); }

public:
BST_Node():data(0){}
BST_Node(T data){ this->data = data; }

void SetData(T data){ this->data = data; }
T GetData() const{ return this->data; }

void SetLeft(unique_ptr<BST_Node<T>> &left){ this->left = std::move(left); }
void SetRight(unique_ptr<BST_Node<T>> &right){ this->right = std::move(right); }

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

};

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
      } else{
        current = current->GetLeftPtr();
      }
    } 
    else if(data > current->GetData()){
      if(current->GetRightPtr() == nullptr){
        unique_ptr<BST_Node<T>> node = make_unique<BST_Node<T>>(data);
        current->SetRight(node);
        return;
      } else{
        current = current->GetRightPtr();
      }
    }
  }

}

template<typename T>
void BinarySearchTree<T>::Remove(T data){
  std::cout << this->root.get()->GetData() << std::endl;

}