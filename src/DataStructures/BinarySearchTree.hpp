#pragma once

template<typename T>
class BST_Node{
private:
T data;
BST_Node<T>* left;
BST_Node<T>* right;

public:
BST_Node():data(0), left(nullptr), right(nullptr){}
BST_Node(T data): left(nullptr), right(nullptr){
  this->data = data;
}

void SetData(T data){ this->data = data; }
T GetData() const{ return this->data; }
void SetLeft(BST_Node<T>* left){ this->left = left; }
void SetRight(BST_Node<T>* right){ this->right = right; }
BST_Node<T>* GetLeft(){ return this->left; }

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
    this->root = new BST_Node<T>;
    this->root->SetData(data);
    return;
  }

  BST_Node<T>* current = this->root;
  BST_Node<T>* next = current->GetLeft();

  // while(current != nullptr){}

  if(data < current->GetData()){
    BST_Node<T>* node = new BST_Node<T>;
    current->SetLeft(node);
    node->SetData(data);
    current = node;
  } else{
    BST_Node<T>* node = new BST_Node<T>;
    current->SetRight(node);
    node->SetData(data);
    current = node;
  }
}

template<typename T>
void BinarySearchTree<T>::Remove(T data){
  std::cout << this->root->GetData() << std::endl;

}