#include <iostream>

#include "proxqueue.h"
#include "graph.h"
#include "shortestpath.h"

using namespace std;

int main() {
  Graph g(10);

  g.generate_edges(.5, 9);
  cout << g << endl;

  ShortestPath sp;

  sp.list_edges(g);

  sp.shortest_path(g, 0, 8);

  return 0;
}
