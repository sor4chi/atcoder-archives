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
    int a, b;
    cin >> a >> b;
    if (b == a * 2 || b == a * 2 + 1) {
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
}
