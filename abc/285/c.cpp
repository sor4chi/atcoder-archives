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
    string s;
    cin >> s;
    string alp = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    ll n = s.size();
    ll ans = 0;
    rep(i, n) {
        ll a = alp.find(s[i]) + 1;
        rep(j, n - i - 1) {
            a *= 26;
        }
        ans += a;
    }
    cout << ans << endl;
}
