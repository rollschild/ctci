#include "graph.h"
#include <queue>
#include <set>

using namespace std;

bool route_between_nodes(Graph &graph, int node_one, int node_two) {
  if (node_one == node_two)
    return false;
  auto itr_one = graph.vertices.find(node_one);
  auto itr_two = graph.vertices.find(node_two);
  if (itr_one == graph.vertices.end() || itr_two == graph.vertices.end()) {
    return false;
  }

  // bi-directional search?

  // bfs first
  queue<int> que{};
  set<int> visited{};
  que.push(itr_one->first);
  while (!que.empty()) {
    int node = que.front();
    visited.insert(node);
    que.pop();
    if (node == node_two) {
      return true;
    }
    for (auto n : graph.vertices[node]->nodes) {
      if (visited.find(n->value_) == visited.end())
        que.push(n->value_);
    }
  }

  return false;
}

int main() {
  Graph graph{};

  add_vertex(graph, 0);
  add_vertex(graph, 1);
  add_vertex(graph, 2);
  add_vertex(graph, 3);
  add_vertex(graph, 4);
  add_vertex(graph, 5);
  add_vertex(graph, 6);

  add_edge(graph, 0, 1);
  add_edge(graph, 1, 2);
  add_edge(graph, 2, 0);
  add_edge(graph, 2, 3);
  add_edge(graph, 3, 2);
  add_edge(graph, 4, 6);
  add_edge(graph, 5, 4);
  add_edge(graph, 6, 5);

  print_graph(graph);

  cout << route_between_nodes(graph, 1, 2) << endl;
  cout << route_between_nodes(graph, 2, 1) << endl;
  cout << route_between_nodes(graph, 3, 4) << endl;
  cout << route_between_nodes(graph, 2, 4) << endl;
  cout << route_between_nodes(graph, 0, 5) << endl;
  cout << route_between_nodes(graph, 3, 1) << endl;
  // 1, 1, 0, 0, 0, 1
  return 0;
}
