#include <bits/stdc++.h>

#include <atcoder/all>

using namespace std;
using namespace atcoder;
typedef long long ll;
template <class T, class... Ts>
void print(const T& a, const Ts&... b) {
    cout << a;
    (void)(cout << ... << (cout << ' ', b));
}
template <class T, class... Ts>
void println(const T& a, const Ts&... b) {
    cout << a;
    (void)(cout << ... << (cout << ' ', b));
    cout << '\n';
}
template <class... T>
void input(T&... a) { (cin >> ... >> a); }
void println() { cout << '\n'; }
#define rep(i, n) for (ll i = 0; i < n; i++)
#define rep1(i, n) for (ll i = 1; i <= n; i++)
#define yesno(a) cout << (a ? "Yes" : "No") << '\n';
#define YESNO(a) cout << (a ? "YES" : "NO") << '\n';

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);

    ll n, k;
    input(n, k);
    vector<string> s(n);
    rep(i, n) input(s[i]);
    vector<map<char, ll>> mps(n);
    rep(i, n) {
        map<char, ll> mp;
        for (auto c : s[i]) {
            mp[c]++;
        }
        mps[i] = mp;
    }
    // ビット全探索
    ll ans = 0;
    rep(i, 1 << n) {
        map<char, ll> mp_all;
        ll cnt = 0;
        rep(j, n) {
            if (i >> j & 1) {
                cnt++;
                for (auto [c, num] : mps[j]) {
                    mp_all[c] += num;
                }
            }
        }
        ll pass = 0;
        for (auto [_, num] : mp_all) {
            if (num == k) pass++;
        }
        ans = max(ans, pass);
    }

    println(ans);

    return 0;
}
