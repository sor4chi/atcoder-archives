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
    int n, for_cnt = 0, against_cnt = 0;
    input(n);
    rep(i, n) {
        string s;
        input(s);
        if (s == "For") for_cnt++;
        if (s == "Against") against_cnt++;
    }
    if (for_cnt > against_cnt)
        print("Yes");
    else
        print("No");
}
