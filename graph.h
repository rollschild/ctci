#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

struct Node {
  int value_;
  vector<Node *> nodes;
  Node(int val) : value_(val), nodes{} {}
};

struct Graph {
  unordered_map<int, Node *> vertices;
  Graph() : vertices{} {}
};

void add_vertex(Graph &graph, int val) {
  if (graph.vertices.find(val) == graph.vertices.end()) {
    // this vertex does not exist
    // need to create new vertex
    Node *node = new Node(val);
    graph.vertices[val] = node;

  } else {
    cout << "This vertex already exists!!!" << endl;
  }
  return;
}

void add_edge(Graph &graph, int origin, int destination) {
  if (graph.vertices.find(origin) == graph.vertices.end()) {
    cout << "Origin does not exist!!!" << endl;
    return;
  }
  // cout << "Origin exists!" << endl;
  vector<Node *> adj_list = graph.vertices[origin]->nodes;
  // cout << "Created temp vector!" << endl;
  vector<Node *>::iterator itr = adj_list.begin();
  // cout << typeid(*itr).name() << endl;
  // cout << (*itr)->value_ << endl;
  while (itr != adj_list.end() && (*itr)->value_ != destination) {
    itr++;
  }

  if (itr != adj_list.end()) {
    cout << "Destination already exists; no need to add one!!!" << endl;
  } else {
    Node *node = new Node(destination);
    graph.vertices[origin]->nodes.push_back(node);
    add_vertex(graph, destination);
  }
  return;
}

void print_graph(Graph &graph) {
  auto vertex_map = graph.vertices;
  for (auto v : vertex_map) {
    cout << v.first << ": ";
    for (auto n : v.second->nodes) {
      cout << n->value_ << " ";
    }
    cout << endl;
  }
  return;
}
