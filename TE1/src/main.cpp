

#include<iostream>

#include <Graph.h>
#include <DijkstraWalker.h>
#include <iostream>
#include <chrono>


auto main( int argc, char** argv ) -> int
{
    auto myGraph = std::make_shared<CGraph>();

    auto manhattanDistance = []( CGraphNode* pNode, CGraph* pGraph )
    {
        auto pEnd = pGraph->GetEndNode();
        float dx = std::labs( pNode->GetPosition().x - pEnd->GetPosition().x );
        float dy = std::labs( pNode->GetPosition().y - pEnd->GetPosition().y );
        return dx + dy;
    };

    auto euclideanDistance = []( CGraphNode* pNode, CGraph* pGraph )
    {
        auto pEnd = pGraph->GetEndNode();
        return (pEnd->GetPosition() - pNode->GetPosition()).Magnitude();
    };

    const int gridCols = 200;
    const int gridRows = 200;

    myGraph->Create( gridCols, gridRows, 50, 50, Connections::EIGHT_DIRECTIONS );
    myGraph->SetHeuristicFunction( euclideanDistance );

    std::unique_ptr<CWalker> pWalker = std::make_unique<CBestFSWalker>();

    using namespace std::chrono;

    std::cout << "Start\n";

    auto start = steady_clock::now();

    auto pGraphCopy = std::make_shared<CGraph>( *myGraph );

    pWalker->SetBegin( 0 );
    pWalker->SetEnd( gridCols * gridRows - 1 );
    pWalker->FindPath( pGraphCopy );

    auto end = steady_clock::now();

    std::cout << "Time to calculate path: " << duration<float>(end - start).count() << std::endl;

    auto path = pWalker->GetPath();

    if ( path.empty() )
    {
        std::cout << "Couldn't find any path" << std::endl;
    }
    else
    {
        std::cout << "Path found: " << std::endl << std::endl;

        int nNodes = path.size() - 1;

        for ( auto pNode : path )
        {
            std::cout << pNode->GetID();

            if ( nNodes-- )
                std::cout << "->";
        }

    }

    pGraphCopy = nullptr;
    pWalker = nullptr;
    myGraph = nullptr;

    std::cin.ignore( std::numeric_limits<std::streamsize>::max() , '\n' );

    return 0;
}

/*int main(int argc, char const *argv[]){

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
}*/