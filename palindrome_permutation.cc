#include <algorithm>
#include <iostream>
#include <map>
#include <string>

using namespace std;

bool permutate_palindrome(string str) {
  while (str.find(" ") != string::npos) {
    str.erase(str.find(" "), 1);
  }

  transform(str.begin(), str.end(), str.begin(), ::tolower);

  map<char, int> dict{};

  for (int i = 0; i < str.length(); ++i) {
    if (dict.find(str[i]) == dict.end())
      // dict[str[i]] == 0;
      dict.insert(pair<char, int>(str[i], 0));
    ++dict[str[i]];
  }

  int num = 0;
  for (auto itr = dict.begin(); itr != dict.end(); ++itr) {
    if (itr->second % 2 != 0)
      ++num;
  }

  if (str.length() % 2 == 0)
    if (num > 0)
      return false;

  if (str.length() % 2 != 0)
    if (num > 1)
      return false;

  return true;
}
/*
bool is_palindrome(string str) {
  for (int i = 0; i < str.length() / 2; ++i) {
    if (str[i] != str[str.length() - i - 1])
      return false;
  }
  return true;
}
*/
int main() {
  cout << permutate_palindrome("Tact Coaa") << endl;
  return 0;
}
