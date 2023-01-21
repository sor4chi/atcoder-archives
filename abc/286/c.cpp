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
    int n, a, b;
    cin >> n >> a >> b;
    vector<char> s(n);
    rep(i, n) cin >> s[i];
    vector<int> count(26);
    rep(i, 26) count[i] = 0;
    rep(i, n) count[s[i] - 'a']++;
    ll total = 0;
    rep(i, 26) if (count[i] % 2 == 1) total += count[i] / 2 + 1;
    total = (ll)floor(total / 2.0);
}
