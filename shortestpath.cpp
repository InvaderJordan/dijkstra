#include <iostream>

#include "proxqueue.h"
#include "graph.h"
#include "shortestpath.h"

using namespace std;

// find shortest path between verticies start and finish
void ShortestPath::shortest_path(Graph& g, int start, int finish) {
  ProxQueue<Edge> open_set;
  ProxQueue<int> closed_set;

  // build initial sets
  closed_set.insert(start, 0);
  for (int i = 0; i < g.get_size(); i++) {
    if (g.get_edge(start, i)) {
      Edge e(start, i, g.get_edge(start, i));
      open_set.insert(e, g.get_edge(start, i));
    }
  }

  /*while (open_set.size() > 0) {
    if (closed_set.contains(finish)) {
      cout << "Finished!" << endl;
      break;
    }
  }*/

  cout << "Closed set: " << endl << closed_set << endl;
  cout << "Open set: " << endl << open_set << endl;
}
