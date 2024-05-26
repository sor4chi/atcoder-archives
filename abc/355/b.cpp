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
template <class T>
void printv(const T& a, string sep = " ", string end = "\n") {
    for (auto x : a) {
        (void)(cout << x << sep);
    }
    cout << end;
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

    ll n, m;
    input(n, m);
    set<ll> a, b;
    rep(i, n) {
        ll ai;
        input(ai);
        a.insert(ai);
    }
    rep(i, m) {
        ll bi;
        input(bi);
        b.insert(bi);
    }
    vector<ll> c;
    c.reserve(n + m);
    c.insert(c.end(), a.begin(), a.end());
    c.insert(c.end(), b.begin(), b.end());

    sort(c.begin(), c.end());

    bool found = false;
    rep1(i, n + m - 1) {
        if (a.count(c[i]) && a.count(c[i - 1])) {
            found = true;
            break;
        }
    }

    yesno(found);

    return 0;
}
