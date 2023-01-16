#include <bits/stdc++.h>
#include <regex>
using namespace std;

int main() {
  string s;
  cin >> s;
  regex re(R"((dream|dreamer|erase|eraser)+)");
  bool match = regex_match(s, re);
  cout << (match ? "YES" : "NO") << endl;
}
