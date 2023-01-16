#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, count = 0;
  cin >> n;
  vector<int> d(n);
  for (int i = 0; i < n; i++) {
    cin >> d.at(i);
  }
  sort(d.begin(), d.end());
  for (int i = 0; i < n; i++) {
    if (d[i] != d[i + 1]) {
      count++;
    }
  }
  cout << count << endl;
}
