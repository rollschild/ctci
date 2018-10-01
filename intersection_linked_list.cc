#include <iostream>

using namespace std;

struct Node {
  int value_;
  Node *next_ptr;
  Node(int val) : value_(val), next_ptr(nullptr) {}
};

pair<Node *, int> get_tail_and_length(Node *head) {
  int l = 0;
  if (head == nullptr)
    return make_pair(nullptr, l);
  ++l;
  while (head->next_ptr != nullptr) {
    head = head->next_ptr;
    ++l;
  }

  return make_pair(head, l);
}

Node *intersection(Node *left, Node *right) {
  if (left == nullptr || right == nullptr)
    return nullptr;

  Node *left_tail = get_tail_and_length(left).first;
  int left_length = get_tail_and_length(left).second;
  Node *right_tail = get_tail_and_length(right).first;
  int right_length = get_tail_and_length(right).second;

  if (left_tail != right_tail)
    return nullptr;

  while (left_length > right_length) {
    left = left->next_ptr;
    --left_length;
  }

  while (left_length < right_length) {
    right = right->next_ptr;
    --right_length;
  }

  while (left != nullptr && right != nullptr) {
    if (left == right)
      return left;
    left = left->next_ptr;
    right = right->next_ptr;
  }

  return nullptr;
}

int main() {
  Node *common = new Node(7);
  common->next_ptr = new Node(2);
  common->next_ptr->next_ptr = new Node(1);

  Node *left = new Node(3);
  left->next_ptr = new Node(1);
  left->next_ptr->next_ptr = new Node(5);
  left->next_ptr->next_ptr->next_ptr = new Node(9);
  left->next_ptr->next_ptr->next_ptr->next_ptr = common;

  Node *right = new Node(4);
  right->next_ptr = new Node(6);
  right->next_ptr->next_ptr = common;

  auto res = intersection(left, right);
  if (res == nullptr)
    cout << "No intersection." << endl;
  else
    cout << res->value_ << endl;

  return 0;
}

