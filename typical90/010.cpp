#include <bits/stdc++.h>
#include <cmath>

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)
#define all(vec) vec.begin(), vec.end()
using P = pair<int, int>;
using T = tuple<int, int, int>;
using graph = vector<vector<int>>;

int main() {
  int n, q;
  cin >> n;
  vector<int> sum_1(n + 1), sum_2(n + 1);
  sum_1.at(0) = 0;
  sum_2.at(0) = 0;
  rep1(i, 1, n + 1) {
    int c, p;
    cin >> c >> p;
    if (c == 1) {
      sum_1.at(i) = sum_1.at(i - 1) + p;
      sum_2.at(i) = sum_2.at(i - 1);
    } else {
      sum_1.at(i) = sum_1.at(i - 1);
      sum_2.at(i) = sum_2.at(i - 1) + p;
    }
  }
  cin >> q;
  vector<int> l(q), r(q);
  rep(i, q) cin >> l.at(i) >> r.at(i);
  rep(i, q) {
    cout << sum_1.at(r.at(i)) - sum_1.at(l.at(i) - 1) << " "
         << sum_2.at(r.at(i)) - sum_2.at(l.at(i) - 1) << endl;
  }
}
