// O(NlogN)
#include <iostream>
#include <vector>

using namespace std;

struct Node {
  int value_;
  Node *left;
  Node *right;
  Node(int val) : value_(val), left(nullptr), right(nullptr) {}
};

Node *insert_tree(vector<int> &sorted, int left, int right);

Node *minimal_tree(vector<int> &sorted) {
  if (sorted.size() == 0)
    return nullptr;
  return insert_tree(sorted, 0, sorted.size() - 1);
}

Node *insert_tree(vector<int> &sorted, int left, int right) {
  if (sorted.size() == 0)
    return nullptr;
  if (left > right)
    return nullptr;

  int pivot = (left + right) / 2;
  Node *node = new Node(pivot);
  node->left = insert_tree(sorted, left, pivot - 1);
  node->right = insert_tree(sorted, pivot + 1, right);

  return node;
}

void dfs_print(Node *root) {
  // pre-order
  if (root == nullptr)
    return;
  cout << root->value_ << " ";
  dfs_print(root->left);
  dfs_print(root->right);
}

int main() {
  vector<int> vec{0, 1, 2, 3, 4, 5, 6, 7, 8};
  Node *root = minimal_tree(vec);
  dfs_print(root);
  cout << endl;
  return 0;
}
