#include <iostream>

using namespace std;

struct LinkedListNode {
  int value_;
  LinkedListNode *next_ptr;

  LinkedListNode(int val) : value_(val), next_ptr(nullptr) {}
};

void delete_node(LinkedListNode *node) {
  if (node == nullptr || node->next_ptr == nullptr)
    return;

  LinkedListNode *next_node = node->next_ptr;
  node->value_ = next_node->value_;
  node->next_ptr = next_node->next_ptr;
  delete next_node;
}

void print_list(LinkedListNode *head) {
  if (head == nullptr)
    return;
  while (head->next_ptr) {
    cout << head->value_ << " -> ";
    head = head->next_ptr;
  }
  cout << head->value_ << endl;
}

int main() {
  LinkedListNode *head = new LinkedListNode(18);
  head->next_ptr = new LinkedListNode(-1);
  head->next_ptr->next_ptr = new LinkedListNode(0);
  head->next_ptr->next_ptr->next_ptr = new LinkedListNode(2037);
  head->next_ptr->next_ptr->next_ptr->next_ptr = new LinkedListNode(66);
  head->next_ptr->next_ptr->next_ptr->next_ptr->next_ptr =
      new LinkedListNode(9);

  delete_node(head->next_ptr->next_ptr->next_ptr);

  print_list(head);

  return 0;
}
