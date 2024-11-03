#pragma once

#include <iostream>
#include <unordered_map>
#include <string>

using std::string;
using std::vector;

class GraphNode{
  private:
  string NodeName;
  vector<GraphNode*> Edges;

  public:
  GraphNode(string name):NodeName(name){}
  string GetName(){ return this->NodeName; }
  void AddNodeEdge(GraphNode* node){ Edges.push_back(node); }
  void PrintNodeEdges();
};

class Graph{
  private:
  vector<GraphNode*> nodes;
  bool isDirected{false};

  public:
  void AddNode(string name);
  void AddEdge(string node1, string node2);
  GraphNode* FindNode(string nodeName);
  void SetDirected(bool state){ this->isDirected = state; }
  bool GetDirected(){ return this->isDirected; }
  void PrintEdges(string nodeName);
  void PrintNodes();
};

void Graph::AddNode(string name){
  for(GraphNode* node : nodes){
    if(node->GetName() == name){
      std::cout << "Node '" << name << "' already exists." << std::endl;
      return;
    }
  }
  GraphNode* node = new GraphNode(name);
  nodes.push_back(node);
}

void Graph::AddEdge(string node1, string node2){
  GraphNode* keyNode = FindNode(node1);
  GraphNode* edgeNode = FindNode(node2);
  keyNode->AddNodeEdge(edgeNode);
  if(!this->isDirected){
    edgeNode->AddNodeEdge(keyNode);
  }
}

GraphNode* Graph::FindNode(string nodeName){
  for(GraphNode* node : nodes){
    if(node->GetName() == nodeName){ return node; }
  } 
  std::cout << "Node " << nodeName << " doesn't exist." << std::endl;
  return nullptr;
}

void Graph::PrintEdges(string nodeName){
  GraphNode* node = FindNode(nodeName);
  node->PrintNodeEdges();
}

void Graph::PrintNodes(){
  for(auto node : nodes){
    std::cout << node->GetName() << std::endl;
  }
}

void GraphNode::PrintNodeEdges(){
  std::cout << this->NodeName << " Edges: ";
  for(auto edge : Edges){ 
    std::cout << edge->GetName() << " ";
  } std::cout << std::endl;
}