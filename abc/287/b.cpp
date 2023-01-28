#include <bits/stdc++.h>
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
    int n, m, cnt = 0;
    input(n, m);
    vector<string> s(n), t(m);
    rep(i, n) {
        string tmp;
        input(tmp);
        s[i] = tmp.substr(3, 3);
    };
    rep(i, m) {
        input(t[i]);
    };
    sort(t.begin(), t.end());
    t.erase(unique(t.begin(), t.end()), t.end());
    rep(i, n) {
        rep(j, t.size()) {
            if (s[i] == t[j]) {
                cnt++;
                break;
            }
        }
    }

    print(cnt);
}
