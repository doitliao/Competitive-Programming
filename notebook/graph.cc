#include <bits/stdc++.h>

using namespace std;

// Once built, it’s hard to modify the edges
// The graph better be static!
// But adding more edges is easy

class Edge{
public:
  int to;
  int next;
};

template <class T>
class AdjacencyListGraph {
public:
  AdjacencyListGraph(int n, int m): nodes(n), LE(n, -1), edges(m){
    eId = 0;
  }
  
  void addNode(int idx, T v) { nodes[idx] = v; }
  void addEdge(int u, int v) { addEdgeLocal(u, v); }
  
  void addBidirectionalEdge(int u, int v) { addEdge(u, v); addEdge(v, u); }
  
  void iterator(int idx) {
    for(int i = LE[idx]; i != -1; i = edges[i].next){
      cout<<"to "<<edges[i].to<<endl;
    }
  }

  // arrays are 0-indexed
  vector<T> nodes;
  vector<int> LE;
  vector<Edge> edges;
  int eId;
  void addEdgeLocal(int u, int v) { edges[eId].to = v; edges[eId].next = LE[u]; LE[u] = eId; eId++; }
};

template <class T>
class TopologicalSort : public AdjacencyListGraph<T> {
public:
  TopologicalSort(int n, int m):AdjacencyListGraph<T>(n, m), deg(n, 0) {}

  void addEdge(int u, int v) { AdjacencyListGraph<T>::addEdge(u, v); deg[v]++;  }

  vector<int> sort(){
    queue<int> q;
    for(int i = 0; i < deg.size(); i++){
      if(deg[i] == 0)q.push(i);
    }
    
    vector<int> s;
    while(!q.empty()){
      int idx = q.front();
      s.push_back(idx);
      q.pop();
      for(int i = AdjacencyListGraph<T>::LE[idx]; i != -1; i = AdjacencyListGraph<T>::edges[i].next){
	deg[AdjacencyListGraph<T>::edges[i].to] -= 1;
	if(deg[AdjacencyListGraph<T>::edges[i].to] == 0)q.push(AdjacencyListGraph<T>::edges[i].to);
      }
    }
    return std::move(s);
  }

  vector<int> deg;
};

template <class T, class W>
class AdjacencyMatrixGraph {
public:
  AdjacencyMatrixGraph(int n): nodes(n), weight(n) {
    for(vector<W> & v : weight) {
      v.resize(n);
    }
  }

  void addNode(int idx, T v) { nodes[idx] = v; }
  void addEdge(int u, int v, W w) { weight[u][v] = w; }
  void addBidirectionalEdge(int u, int v, W w) { addEdge(u, v, w); addEdge(v, u, w); }

  vector<T> nodes;
  vector<vector<W> > weight;
};

int main() {
  //AdjacencyListGraph<unsigned> g(4, 8);
  TopologicalSort<unsigned> g(4, 8);

  g.addNode(0, 13);
  g.addNode(1, 12);
  g.addNode(2, 11);
  g.addNode(3, 10);

  g.addEdge(0, 1);
  g.addEdge(0, 3);
  g.addEdge(2, 1);
  g.addEdge(2, 3);

  //g.iterator(2);
  //g.iterator(0);

  //cout<<g.deg[3]<<endl;
  auto x = g.sort();
  for(int i : x){
    cout<<"Sort "<<i<<endl;
  }
}
