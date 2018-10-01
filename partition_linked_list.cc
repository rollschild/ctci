#include <iostream>

using namespace std;

struct Node {
  int value_;
  Node *next_ptr;
  Node(int val) : value_(val), next_ptr(nullptr) {}
};

Node *partition_linked_list(Node *head, int val) {
  Node *new_head = new Node(head->value_);
  Node *new_tail = new_head;
  head = head->next_ptr;
  while (head != nullptr) {
    if (head->value_ >= val) {
      // add to tail
      Node *node = new Node(head->value_);
      new_tail->next_ptr = node;
      new_tail = new_tail->next_ptr;
    } else {
      Node *node = new Node(head->value_);
      node->next_ptr = new_head;
      new_head = node;
    }
    head = head->next_ptr;
  }

  return new_head;
}

void print_linked_list(Node *head) {
  if (head == nullptr)
    return;
  while (head->next_ptr) {
    cout << head->value_ << " -> ";
    head = head->next_ptr;
  }
  cout << head->value_ << endl;
  return;
}

int main() {
  Node *head = new Node(3);
  head->next_ptr = new Node(5);
  head->next_ptr->next_ptr = new Node(8);
  head->next_ptr->next_ptr->next_ptr = new Node(5);
  head->next_ptr->next_ptr->next_ptr->next_ptr = new Node(10);
  head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr = new Node(2);
  head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr =
      new Node(1);

  auto new_head = partition_linked_list(head, 5);

  print_linked_list(new_head);

  return 0;
}
