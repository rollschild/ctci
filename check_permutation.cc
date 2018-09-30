#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

bool is_permutation(string str1, string str2) {
  if (str1.length() != str2.length())
    return false;
  sort(str1.begin(), str1.end(), [](char l, char r) { return l < r; });
  sort(str2.begin(), str2.end(), [](char l, char r) { return l < r; });

  return str1 == str2;
}

int main() {
  cout << is_permutation("hello", "llohe") << endl;
  cout << is_permutation("hello", "lloha") << endl;

  return 0;
}
