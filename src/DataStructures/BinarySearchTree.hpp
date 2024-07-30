#pragma once

template<typename T>
class BST_Node{
private:
T data;
T* left;
T* right;

public:
BST_Node():data(0), left(nullptr), right(nullptr){}
BST_Node(T data): left(nullptr), right(nullptr){
  this->data = data;
}

void SetData(T data){ this->data = data; }
T GetData() const{ return this->data; }

};

template<typename T>
class BinarySearchTree{
private:
BST_Node<T>* root;

public:
BinarySearchTree():root(nullptr){}
~BinarySearchTree(){}
void Insert(T data);
void Remove(T data);

};

template<typename T>
void BinarySearchTree<T>::Insert(T data){
  if(this->root == nullptr){
    std::cout << "NULL" << std::endl;
    this->root->SetData(data);
  }
}