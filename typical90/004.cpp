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

int main() {
  int h, w;
  cin >> h >> w;
  vector<vector<int>> a(h, vector<int>(w));
  rep(i, h) {
    rep(j, w) { cin >> a.at(i).at(j); }
  }
  vector<int> h_sum(h);
  vector<int> w_sum(w);
  rep(i, h) {
    rep(j, w) {
      h_sum.at(i) += a.at(i).at(j);
      w_sum.at(j) += a.at(i).at(j);
    }
  }
  rep(i, h) {
    rep(j, w) {
      int total = 0;
      total += h_sum.at(i);
      total += w_sum.at(j);
      total -= a.at(i).at(j);
      cout << total << " ";
    }
    cout << endl;
  }
}
