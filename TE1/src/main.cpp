

#include<iostream>

#include<algorithm.hpp>
#include<structures.hpp>

using namespace structures;
using namespace std;


// print all neighboring vertices of given vertex
void printList(Node* ptr, int i)
{
  while (ptr != nullptr)
  {
    cout << "(" << i << ", " << ptr->val
      << ", " << ptr->cost << ") ";

    ptr = ptr->next;
  }

  cout << endl;
}

int main(int argc, char const *argv[]){

  Edge edges[] =
  {
    // (x, y, w) -> edge from x to y having weight w
    { 0, 1, 2 }, { 1, 2, 4 }

  };

  // Number of vertices in the graph
  int N = 6;

  // calculate number of edges
  int n = sizeof(edges)/sizeof(edges[0]);

  // construct graph
  Graph graph(edges, n, N);

  // print adjacency list representation of graph
  for (int i = 0; i < N; i++)
  {
    // print all neighboring vertices of vertex i
    printList(graph.head[i], i);
  }
  

  return 0;
}