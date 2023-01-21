#include <bits/stdc++.h>
#include <regex.h>
using namespace std;
typedef pair<int, int> P;
typedef long long ll;
typedef long double ld;
template <class T, class... Ts>
void print(const T& a, const Ts&... b) {
    cout << a;
    (cout << ... << (cout << ' ', b));
    cout << '\n';
}
template <class... T>
void input(T&... a) { (cin >> ... >> a); }
void print() { cout << '\n'; }
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n), b(n);

    vector<vector<bool>> dp(n + 1, vector<bool>(x + 1, false));
    dp[0][0] = true;
    rep(i, n) cin >> a[i] >> b[i];
    rep(i, n) {
        rep(j, x + 1) {
            rep(k, b[i] + 1) {
                if (j - k * a[i] >= 0) {
                    dp[i + 1][j] = dp[i + 1][j] || dp[i][j - k * a[i]];
                }
            }
        }
    }
    print(dp[n][x] ? "Yes" : "No");
}
