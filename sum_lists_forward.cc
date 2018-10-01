#include <iostream>
#include <stack>

using namespace std;

struct Node {
  int value_;
  Node *next_ptr;
  Node(int val) : value_(val), next_ptr(nullptr) {}
};

Node *sum_lists(Node *lhs, Node *rhs) {
  stack<int> lhs_num{};
  stack<int> rhs_num{};
  stack<int> re{};

  while (lhs != nullptr) {
    lhs_num.push(lhs->value_);
    lhs = lhs->next_ptr;
  }
  while (rhs != nullptr) {
    rhs_num.push(rhs->value_);
    rhs = rhs->next_ptr;
  }

  int carry = 0;
  int res = 0;
  while (!lhs_num.empty() || !rhs_num.empty()) {
    if (!lhs_num.empty() && !rhs_num.empty()) {
      res = lhs_num.top() + rhs_num.top() + carry;
      lhs_num.pop();
      rhs_num.pop();
    } else if (!lhs_num.empty()) {
      res = lhs_num.top() + carry;
      lhs_num.pop();
    } else {
      res = rhs_num.top() + carry;
      rhs_num.pop();
    }

    if (res >= 10) {
      carry = 1;
      res = res - 10;
    } else {
      carry = 0;
    }

    re.push(res);
  }

  if (carry > 0)
    re.push(1);

  Node *head = nullptr;
  Node *curr = nullptr;
  while (!re.empty()) {
    int d = re.top();
    Node *node = new Node(d);
    if (head == nullptr) {
      head = node;
      curr = node;
    } else {
      curr->next_ptr = node;
      curr = node;
    }

    re.pop();
  }

  return head;
}

void print_list(Node *head) {
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
  Node *lhs_head = new Node(6);
  lhs_head->next_ptr = new Node(1);
  lhs_head->next_ptr->next_ptr = new Node(7);
  lhs_head->next_ptr->next_ptr->next_ptr = new Node(8);

  Node *rhs_head = new Node(8);
  rhs_head->next_ptr = new Node(4);
  rhs_head->next_ptr->next_ptr = new Node(2);
  rhs_head->next_ptr->next_ptr->next_ptr = new Node(6);

  auto head = sum_lists(lhs_head, rhs_head);

  print_list(head);

  return 0;
}
