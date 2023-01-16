#include <bits/stdc++.h>
using namespace std;

int main() {
  int n, a, b, total = 0;
  cin >> n >> a >> b;

  for (int i = 1; i <= n; i++) {
    int sum = 0, j = i;
    while (j > 0) {
      sum += j % 10;
      j /= 10;
    }

    if (sum >= a && sum <= b) {
      total += i;
    }
  }
  cout << total << endl;
}
