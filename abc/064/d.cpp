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
    int n, lbrace_count = 0, rbrace_count = 0;
    input(n);
    string s;
    input(s);
    char c = s[0];
    rep(i, n) {
        if (s[i] == '(') {
            lbrace_count++;
        } else {
            if (lbrace_count > 0) {
                lbrace_count--;
            } else {
                rbrace_count++;
            }
        }
    }
    print(string(rbrace_count, '(') + s + string(lbrace_count, ')'));
}
