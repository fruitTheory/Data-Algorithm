#include "include.hpp"
#include <iostream>

int main(){

  std::cout << "Hello" << std::endl;

  Graph graph;
  graph.AddNode("Buddy");
  graph.AddNode("Bestie");
  graph.AddNode("Testie");
  graph.AddEdge("Buddy", "Bestie");
  graph.AddEdge("Buddy", "Testie");
  graph.PrintNodes();
  graph.PrintEdges("Buddy");
  graph.PrintEdges("Bestie");

  std::cout << "Goodbye" << std::endl;

  return EXIT_SUCCESS;
}