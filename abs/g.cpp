#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, p = 0, q = 0;
  cin >> n;
  vector<int> a(n);
  for (int i = 0; i < n; i++) {
    cin >> a.at(i);
  }
  sort(a.begin(), a.end(), greater<int>());
  for (int i = 0; i < n; i++) {
    if (i % 2) {
      p += a[i];
    } else {
      q += a[i];
    }
  }
  cout << q - p << endl;
}
