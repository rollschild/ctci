#include <iostream>
#include <string>

using namespace std;

string urlify(string str) {
  // trim string first
  str.erase(str.find_last_not_of(" \n\t\r") + 1);
  while (str.find(" ") != string::npos) {
    str.replace(str.find(" "), 1, "%20");
  }

  return str;
}

int main() {
  cout << urlify("Mr John Smith    ") << endl;
  return 0;
}
