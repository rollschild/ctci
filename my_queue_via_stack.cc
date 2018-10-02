#include <iostream>
#include <stack>

using namespace std;

template <typename T> class MyQueue {
public:
  MyQueue() : stckNew{}, stckOld{} {}

  void push(T val) { stckNew.push(val); }

  void pop() {
    // pop from stckOld
    if (stckOld.empty()) {
      transfer_stack();
    }
    stckOld.pop();
  }

  int size() { return stckNew.size() + stckOld.size(); }

  T front() {
    if (stckOld.empty()) {
      transfer_stack();
    }
    return stckOld.top();
  }

  T back() {}

  void transfer_stack() {
    if (stckOld.empty()) {
      while (!stckNew.empty()) {
        stckOld.push(stckNew.top());
        stckNew.pop();
      }
    }
  }

private:
  stack<T> stckNew;
  stack<T> stckOld;
};

int main() {
  MyQueue<int> my_queue{};
  my_queue.push(2037);
  my_queue.push(-1);
  my_queue.push(88);
  my_queue.push(4);
  cout << "Front value is: " << my_queue.front() << endl;
  my_queue.pop();
  cout << "New front is: " << my_queue.front() << endl;
  my_queue.pop();
  cout << "Newes front is... " << my_queue.front() << endl;
  // should be 88

  return 0;
}
