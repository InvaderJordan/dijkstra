#ifndef PROXQUEUE_H
#define PROXQUEUE_H

#include <queue>

class Edge {
public:
  Edge(int _x, int _y, int edge=0):x(_x),y(_y),val(edge) {}
  ~Edge() {}

  inline int getVal(void) const {return val;}
  inline int getX(void) const {return x;}
  inline int getY(void) const {return y;}
  inline void setVal(int v) {val = v;}

  friend std::ostream& operator<<(std::ostream& os, const Edge& e) {
    std::cout << "(" << e.x << "," << e.y << "): " << e.val;

    return os;
  }

  friend bool operator==(const Edge& e1, const Edge& e2) {
    return (e1.x == e2.x && e1.y == e2.y);
  }

protected:
  int x;
  int y;
  int val;
};

template <class T>
class ProxQueue {
public:
  ProxQueue() {}
  ~ProxQueue() {}

  void insert(T elem, int val) {
    queue.push_back(std::make_tuple(elem, val));
  }

  std::tuple<T, int> minPriority(void) {
    int min_idx = get_min_idx();
    T min_elem = std::get<0>(queue[min_idx]);
    int min_val = std::get<1>(queue[min_idx]);
    queue.erase(queue.begin() + min_idx);
    return std::make_tuple(min_elem, min_val);
  }

  bool contains(T e) {
    for (auto itr : queue) {
      if (std::get<0>(itr) == e) {
        return true;
      }
    }
    return false;
  }

  void modify(T e, int val) {
    for (auto itr : queue) {
      if (std::get<0>(itr) == e) {
        std::get<1>(itr) = val;
      }
    }
  }

  int get_val(T e) {
    for (auto itr : queue) {
      if (std::get<0>(itr) == e) {
        return std::get<1>(itr);
      }
    }
    return -1;
  }

  std::tuple<T, int> top(void) {
    int idx = get_min_idx();
    return queue[idx];
  }

  int size(void) {
    return queue.size();
  }

  friend std::ostream& operator<<(std::ostream& os, const ProxQueue& pq) {
    for (int i = 0; i < pq.queue.size(); i++) {
      std::cout << std::get<0>(pq.queue[i]) << ": " << std::get<1>(pq.queue[i]) << std::endl;
    }

    return os;
  }

private:
  std::vector< std::tuple<T,int> > queue;

  // return index into edges of the min edge
  int get_min_idx(void) {
    int min_val = INT_MAX;
    int min_idx = 0;
    for (int i = 0; i < queue.size(); i++) {
      if (std::get<1>(queue[i]) < min_val) {
        min_val = std::get<1>(queue[i]);
        min_idx = i;
      }
    }
    return min_idx;
  }
};

#endif // PROXQUEUE_H
