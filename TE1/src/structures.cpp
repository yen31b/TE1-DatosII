

#include <structures.hpp>

namespace structures {

  // Function to allocate new node of Adjacency List
  Node* Graph::getAdjListNode(int value, int weight, Node* head)
  {
    Node* newNode = new Node;
    newNode->val = value;
    newNode->cost = weight;

    // point new node to current head
    newNode->next = head;

    return newNode;
  }

  // Constructor
  Graph::Graph(Edge edges[], int n, int N)
  {
    // allocate memory
    head = new Node*[N]();
    this->N = N;

    // initialize head pointer for all vertices
    for (int i = 0; i < N; ++i)
      head[i] = nullptr;

    // add edges to the directed graph
    for (unsigned i = 0; i < n; i++)
    {
      int src = edges[i].src;
      int dest = edges[i].dest;
      int weight = edges[i].weight;

      // insert in the beginning
      Node* newNode = getAdjListNode(dest, weight, head[src]);

      // point head pointer to new node
      head[src] = newNode;

      // Uncomment below lines for undirected graph

      /*
      newNode = getAdjListNode(src, weight, head[dest]);

      // change head pointer to point to the new node
      head[dest] = newNode;
      */
    }
  }

  // Destructor
  Graph::~Graph() {
    for (int i = 0; i < N; i++)
      delete[] head[i];

    delete[] head;
  }

}




