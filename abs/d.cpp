#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, m = 1000000000;
  cin >> n;

  for (int i = 0; i < n; i++) {
    int p, q = 0;
    cin >> p;
    for (; p % 2 == 0; p /= 2) {
      q++;
    }
    m = min(m, q);
  }
  cout << m << endl;
}
