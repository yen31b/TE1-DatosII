#ifndef structures_hpp
#define structures_hpp

namespace structures {
  
  // Data structure to store Adjacency list nodes
  struct Node {
    int val, cost;
    Node* next;
  };

  // Data structure to store graph edges
  struct Edge {
    int src, dest, weight;
  };

  class Graph {

    public:
      Graph(Edge edges[], int n, int N);
      ~Graph();
      Node* getAdjListNode(int value, int weight, Node* head);
      int N;  // number of nodes in the graph
      // An array of pointers to Node to represent
      // adjacency list
      Node **head;

  };

}




#endif