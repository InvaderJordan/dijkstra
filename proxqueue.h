#include <queue>

class Edge {
public:
  Edge(int _x, int _y, int edge=0):x(_x),y(_y),val(edge) {}
  ~Edge() {}

  int getVal(void) const {return val;}

protected:
  int x;
  int y;
  int val;
};

class Compare {
public:
  bool operator() (const Edge& e1, const Edge& e2) {
    return e1.getVal() > e2.getVal();
  }
};

class ProxQueue {
public:
  ProxQueue() {}
  ~ProxQueue() {}

  void insert(Edge e) {
    pq.push(e);
  }

  Edge minPriority(void) {
    Edge e = pq.top();
    pq.pop();
    return e;
  }

private:
  std::priority_queue <Edge, std::vector<Edge>, Compare> pq;

};
