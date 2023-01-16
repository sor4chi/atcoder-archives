#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, y, a, b, c, a_max, b_max;
  cin >> n >> y;
  a_max = y / 10000;
  for (int a = 0; a <= a_max; a++) {
    int z = y - 10000 * a;
    b_max = z / 5000;
    for (int b = 0; b <= b_max; b++) {
      int l = z - 5000 * b;
      c = l / 1000;
      if (a + b + c == n) {
        cout << a << " " << b << " " << c << endl;
        return 0;
      }
    }
  }
  cout << -1 << " " << -1 << " " << -1 << endl;
}
