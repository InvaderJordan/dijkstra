#include <iostream>
#include <vector>
#include <ctime>

#include "graph.h"

using namespace std;

ostream& operator<<(ostream& os, const Graph& g) {
  for (int i = 0; i < g.conn_matrix.size(); i++) {
    for (int j = 0; j < g.conn_matrix[i].size(); j++) {
      cout << g.conn_matrix[i][j] << " ";
    }
    cout << endl;
  }
  return os;
}

void Graph::neighbors(int x) {
  for (int i = 0; i < conn_matrix[x].size(); i++) {
    if (conn_matrix[x][i] != 0) {
      cout << i << ": " << conn_matrix[x][i] << endl;
    }
  }
}

void Graph::generate_edges(double density, int edge_range) {
  conn_matrix.resize(verts);
  for (int i = 0; i < verts; i++) {
    conn_matrix[i].resize(verts);
  }

  srand(time(0));

  for (int i = 0; i < verts; i++) {
    for (int j = i; j < verts; j++) {
      if (i == j || ((rand() % 100) > (density * 100))) {
        conn_matrix[i][j] = 0;
      } else {
        conn_matrix[i][j] = conn_matrix[j][i] = rand() % edge_range;
        edges++;
      }
    }
  }
}
