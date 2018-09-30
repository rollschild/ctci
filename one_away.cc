#include <iostream>
#include <string>

using namespace std;

bool is_replace(string &str1, string &str2);
bool is_insert(string &str1, string &str2);
bool is_remove(string &str1, string &str2);

bool one_away(string str1, string str2) {
  if (str1.length() == str2.length())
    return is_replace(str1, str2);
  else if (str1.length() > str2.length())
    return is_remove(str1, str2);
  else
    return is_insert(str1, str2);
}

bool is_remove(string &str1, string &str2) {
  if (str1.length() > str2.length() + 1)
    return false;
  for (int i = 0; i < str1.length(); ++i) {
    string tmp = "";
    tmp = str1.substr(0, i) + str1.substr(i + 1, str1.length() - i - 1);
    if (tmp == str2)
      return true;
  }

  return false;
}

bool is_insert(string &str1, string &str2) {
  if (str2.length() > str1.length() + 1)
    return false;
  for (int i = 0; i < str2.length(); ++i) {
    string tmp = "";
    tmp = str2.substr(0, i) + str2.substr(i + 1, str2.length() - i - 1);
    if (tmp == str1)
      return true;
  }

  return false;
}

bool is_replace(string &str1, string &str2) {
  // sort(str1.begin(), str1.end(), [](char l, char r) { return l < r; });
  // sort(str2.begin(), str2.end(), [](char l, char r) { return l < r; });

  int num = 0;

  for (int i = 0; i < str1.length(); ++i) {
    if (str1[i] != str2[i])
      ++num;
  }

  return num == 1;
}

int main() {
  cout << one_away("pale", "ple") << endl;
  cout << one_away("pales", "pale") << endl;
  cout << one_away("pale", "bale") << endl;
  cout << one_away("pale", "bake") << endl;

  return 0;
}
