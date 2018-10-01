#include <iostream>

using namespace std;

struct Node {
  int value_;
  Node *next_ptr;
  Node(int val) : value_(val), next_ptr(nullptr) {}
};

Node *loop_detection(Node *head) {
  if (head == nullptr)
    return nullptr;
  Node *slow = head;
  Node *fast = head;

  while (fast && fast->next_ptr) {
    slow = slow->next_ptr;
    fast = fast->next_ptr->next_ptr;
    if (slow == fast)
      break;
  }

  if (fast == nullptr || fast->next_ptr == nullptr)
    return nullptr;

  slow = head;
  while (slow != fast) {
    slow = slow->next_ptr;
    fast = fast->next_ptr;
  }

  return fast;
}

int main() {
  Node *a = new Node(1);
  Node *b = new Node(2);
  Node *c = new Node(3);
  Node *d = new Node(4);
  Node *e = new Node(5);
  Node *f = new Node(6);

  a->next_ptr = b;
  b->next_ptr = c;
  c->next_ptr = d;
  d->next_ptr = e;
  e->next_ptr = f;
  // f->next_ptr = c;

  if (loop_detection(a))
    cout << loop_detection(a)->value_ << endl;
  else
    cout << "Not a loop." << endl;

  return 0;
}
