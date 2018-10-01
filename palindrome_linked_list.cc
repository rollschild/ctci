#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int value_;
  Node *next_ptr;
  Node(int val) : value_(val), next_ptr(nullptr) {}
};

bool check_palindrome(Node *head) {
  stack<int> dict{};
  Node *curr = head;
  while (curr != nullptr) {
    dict.push(curr->value_);
    curr = curr->next_ptr;
  }

  while (!dict.empty() && head != nullptr) {
    if (dict.top() != head->value_)
      return false;
    dict.pop();
    head = head->next_ptr;
  }
  return true;
}

int main() {
  Node *head = new Node(6);
  head->next_ptr = new Node(0);
  head->next_ptr->next_ptr = new Node(0);
  head->next_ptr->next_ptr->next_ptr = new Node(9);

  cout << check_palindrome(head) << endl;

  return 0;
}
