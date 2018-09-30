#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool is_unique(string str) {
  sort(str.begin(), str.end(), [](char l, char r) { return l - r < 0; });
  for (int i = 0; i < str.length() - 1; ++i) {
    if (str[i] == str[i + 1])
      return false;
  }
  return true;
}

int main() {
  cout << is_unique("hello") << endl;
  cout << is_unique("whatisup?") << endl;
  cout << is_unique("abcdefg") << endl;
  return 0;
}

