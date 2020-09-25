#include <iostream>

#include "proxqueue.h"
#include "graph.h"
#include "shortestpath.h"

using namespace std;

// find shortest path between verticies start and finish
void ShortestPath::shortest_path(Graph& g, int start, int finish) {
  ProxQueue open_set, closed_set;
  Edge init(start, start, 0), end(finish, finish);

  // build initial sets
  closed_set.insert(init);
  for (int i = 0; i < g.get_size(); i++) {
    if (g.get_edge(start, i)) {
      Edge e(start, i, g.get_edge(start, i));
      open_set.insert(e);
    }
  }

  while (open_set.size() > 0) {
    if (closed_set.contains(end)) {
      cout << "Finished!" << endl;
      break;
    }
  }

  cout << "Closed set: " << endl << closed_set << endl;
  cout << "Open set: " << endl << open_set << endl;
}
