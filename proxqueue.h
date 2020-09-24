#include <queue>

class Edge {
public:
  Edge(int _x, int _y, int edge=0):x(_x),y(_y),val(edge) {}
  ~Edge() {}

  inline int getVal(void) const {return val;}
  inline int getX(void) const {return x;}
  inline int getY(void) const {return y;}

protected:
  int x;
  int y;
  int val;
};

class ProxQueue {
public:
  ProxQueue() {}
  ~ProxQueue() {}

  void insert(Edge e) {
    edges.push_back(e);
  }

  Edge minPriority(void) {
    int min_idx = get_min_idx();
    Edge min_edge = edges[min_idx];
    edges.erase(edges.begin() + min_idx);
    return min_edge;
  }

  bool contains(Edge e) {
    for (auto itr : edges) {
      if (itr.getX() == e.getX() && itr.getY() == e.getY()) {
        return true;
      }
    }
    return false;
  }

  Edge top(void) {
    int idx = get_min_idx();
    return edges[idx];
  }

  int size(void) {
    return edges.size();
  }

private:
  std::vector<Edge> edges;

  // return index into edges of the min edge
  int get_min_idx(void) {
    int min_val = INT_MAX;
    int min_idx = 0;
    for (int i = 0; i < edges.size(); i++) {
      if (edges[i].getVal() < min_val) {
        min_val = edges[i].getVal();
        min_idx = i;
      }
    }
    return min_idx;
  }
};
