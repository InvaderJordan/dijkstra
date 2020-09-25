#include <iostream>

#include "proxqueue.h"
#include "graph.h"
#include "shortestpath.h"

using namespace std;

int main() {
  Graph g(10);

  g.generate_edges(.25, 9);
  cout << g;

  ShortestPath sp;

  sp.list_edges(g);

  return 0;
}
