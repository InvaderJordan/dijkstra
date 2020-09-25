#ifndef SHORTESTPATH_H
#define SHORTESTPATH_H

#include "proxqueue.h"
#include "graph.h"

class ShortestPath {
public:
  ShortestPath() {}
  ~ShortestPath() {}

  void list_edges(Graph& g) {
    for (int i = 0; i < g.get_size(); i++) {
      for (int j = i; j < g.get_size(); j++) {
        if (g.get_edge(i, j) > 0) {
          std::cout << "(" << i << "," << j << "): " << g.get_edge(i,j) << std::endl;
        }
      }
    }
    std::cout << std::endl;
  }

  void shortest_path(Graph& g, int start, int finish);

private:

};

#endif // SHORTESTPATH_H
