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
    cout << endl;
}
template <class... T>
void input(T&... a) { (cin >> ... >> a); }
void print() { cout << endl; }
#define rep(i, n) for (ll i = 0; i < n; i++)

int main() {
    int n;
    cin >> n;
    string sa, sb;
    cin >> sa >> sb;
    rep(i, n) {
        int a = sa[i] - '0', b = sb[i] - '0';
        if (a < b) swap(sa[i], sb[i]);
    }
    ll a = 0, b = 0;
    rep(i, n) {
        a = (a * 10 + sa[i] - '0') % 998244353;
        b = (b * 10 + sb[i] - '0') % 998244353;
    }
    print(a * b % 998244353);
}
