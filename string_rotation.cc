#include <iostream>
#include <string>

using namespace std;

bool is_substring(string &str1, string &str2) {
  if (str1.find(str2) != string::npos)
    return true;
  else
    return false;
}

bool string_rotation(string str1, string str2) {
  string combo = str1 + str1;
  return is_substring(combo, str2);
}

int main() {
  cout << string_rotation("erbotltewat", "waterbottle") << endl;

  return 0;
}
