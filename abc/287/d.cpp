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

bool judge_match(string a, string b) {
    int size = a.size();
    bool flag = true;
    rep(i, size) {
        if (a[i] == '?') continue;
        if (b[i] == '?') continue;
        if (a[i] != b[i]) {
            flag = false;
            break;
        }
    }
    return flag;
}

int main() {
    string s, t;
    input(s, t);
    rep(i, t.size() + 1) {
        string a = s.substr(0, i) + s.substr(s.size() - t.size() + i);
        print(judge_match(a, t) ? "Yes" : "No");
    }
}
