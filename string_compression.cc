#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string compression(string str) {
  /*
  unordered_map<char, int> dict{};

  for (int i = 0; i < str.length(); ++i) {
    if (dict.find(str[i]) == dict.end())
      dict.insert(pair<char, int>(str[i], 0));
    dict[str[i]]++;
  }
  */
  string res = "";
  int pos = 0;
  int num = 1;

  while (pos < str.length()) {
    if (str[pos] == str[pos + 1]) {
      ++num;
    } else {
      res = res + str[pos] + to_string(num);
      num = 1;
    }

    ++pos;
  }
  /*
  for (auto itr = dict.begin(); itr != dict.end(); ++itr) {
    res = res + itr->first + to_string(itr->second);
  }
  */

  if (res.length() > str.length())
    return str;
  else
    return res;
}

int main() {
  cout << compression("aabcccccaaa") << endl;
  return 0;
}
