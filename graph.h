#ifndef GRAPH_H
#define GRAPH_H

class Graph {
public:
  Graph(int verticies):verts(verticies),edges(0) {}
  ~Graph() {}

  void generate_edges(double density, int edge_range);
  void neighbors(int x);
  friend std::ostream& operator<<(std::ostream& os, const Graph& g);

  const int v(void) {return verts;}
  int e(void) {return edges;}
  int get_edge(int x, int y) {return conn_matrix[x][y];}
  void add_edge(int x, int y, int e) {conn_matrix[x][y] = conn_matrix[y][x] = e;}
  void delete_edge(int x, int y) {conn_matrix[x][y] = conn_matrix[y][x] = 0;}
  int get_size(void) {return conn_matrix.size();}
  void set_edges(std::vector<std::vector <int> > v) {
    conn_matrix = v;
  }


private:
  const int verts;
  int edges;
  std::vector<std::vector <int> > conn_matrix;
};

#endif // GRAPH_H
