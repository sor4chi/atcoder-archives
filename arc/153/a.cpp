#include <bits/stdc++.h>

#include <cmath>
#include <iomanip>
#include <regex>
#include <sstream>

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
    int n, cnt = 0;
    cin >> n;
    rep1(f, 100, 1000) {
        rep(j, 1000) {
            cnt++;
            if (cnt == n) {
                ostringstream sa, sb;
                sa << f;
                sb << std::setw(3) << std::setfill('0') << j;
                cout << sa.str().substr(0, 1)
                     << sa.str().substr(0, 1)
                     << sb.str().substr(0, 1)
                     << sb.str().substr(1, 1)
                     << sa.str().substr(1, 1)
                     << sa.str().substr(1, 1)
                     << sa.str().substr(2, 1)
                     << sb.str().substr(2, 1)
                     << sa.str().substr(2, 1)
                     << endl;
                return 0;
            }
        }
    }
}
