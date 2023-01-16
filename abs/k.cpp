#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, ok = 1, dist, time;
  cin >> n;
  vector<int> t(n), x(n), y(n);
  for (int i = 0; i < n; i++) {
    cin >> t.at(i) >> x.at(i) >> y.at(i);
  }
  for (int i = 0; i < n; i++) {
    dist = abs(x[i] - x[i - 1]) + abs(y[i] - y[i - 1]);
    time = t[i] - t[i - 1];
    if (time < dist) {
      ok = 0;
      break;
    }
    if (time % 2 != dist % 2) {
      ok = 0;
      break;
    }
  }
  cout << (ok ? "Yes" : "No") << endl;
}
