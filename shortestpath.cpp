#include <iostream>

#include "proxqueue.h"
#include "graph.h"
#include "shortestpath.h"

using namespace std;

// find shortest path between verticies start and finish
void ShortestPath::shortest_path(Graph& g, int start, int finish) {
  ProxQueue<int> open_set;
  ProxQueue<int> closed_set;
  vector<Edge> path;
  int currnode = start;

  // build initial sets
  closed_set.insert(start, 0);
  for (int i = 0; i < g.get_size(); i++) {
    if (g.get_edge(start, i)) {
      open_set.insert(i, g.get_edge(start, i));
    }
  }

  while (open_set.size() > 0) {
    auto nextpath = open_set.minPriority();
    int nextnode = get<0>(nextpath);
    int nextval = get<1>(nextpath);
    closed_set.insert(nextnode, nextval);
    path.push_back(Edge(currnode, nextnode, nextval));

    if (closed_set.contains(finish)) {
      cout << "Finished!  Shortest path: " << closed_set.get_val(finish) << endl;
      break;
    }

    bool open_set_addition = false;
    for (int i = 0; i < g.get_size(); i++) {
      int val = g.get_edge(nextnode, i);
      // check if an edge exists
      if (val) {
        if (!closed_set.contains(i)) {
          if (!open_set.contains(i)) {
            open_set.insert(i, (val + nextval));
            open_set_addition = true;
          }
          else if ((val + nextval) < open_set.get_val(i)) {
            open_set.modify(i, (val + nextval));
            open_set_addition = true;
          }
        }
      }
    }

    if (open_set_addition) {
      currnode = nextnode;
    } else {
      currnode = path.back().getX();
      path.pop_back();
    }

    cout << "Closed set: " << endl << closed_set << endl;
    cout << "Open set: " << endl << open_set << endl;
    cout << "Path: " << endl;
    for (auto itr : path) {
      cout << itr << endl;
    }
    cout << endl;
  }

  if (open_set.size() > 0) {
    cout << "Final Path: " << endl;
    for (auto itr : path) {
      cout << itr << endl;
    }
    cout << endl;
  }
}
