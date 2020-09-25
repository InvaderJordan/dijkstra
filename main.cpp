#include <iostream>

#include "proxqueue.h"
#include "graph.h"
#include "shortestpath.h"

using namespace std;

int main() {
  vector<vector <int> > test = {
  // S  A  B  C  D  E  F  G  T
    {0, 4, 3, 0, 7, 0, 0, 0, 0}, // S
    {4, 0, 0, 1, 0, 0, 0, 0, 0}, // A
    {3, 0, 0, 0, 4, 0, 0, 0, 0}, // B
    {0, 1, 0, 0, 3, 1, 0, 0, 0}, // C
    {7, 0, 4, 3, 0, 1, 5, 0, 3}, // D
    {0, 0, 0, 1, 1, 0, 0, 2, 4}, // E
    {0, 0, 0, 0, 5, 0, 0, 0, 5}, // F
    {0, 0, 0, 0, 0, 2, 0, 0, 3}, // G
    {0, 0, 0, 0, 3, 4, 5, 3, 0}, // T
  };
  Graph g(8);

  g.generate_edges(.5, 9);
  //g.set_edges(test);
  cout << g << endl;

  ShortestPath sp;

  sp.list_edges(g);

  sp.shortest_path(g, 0, g.get_size() - 1);

  return 0;
}
