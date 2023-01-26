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
    int t;
    cin >> t;
    rep(i, t) {
        int n;
        cin >> n;
        vector<int> a(n), b(n), kind(5000 + 1);
        rep(i, n) {
            cin >> a[i];
            kind[a[i]]++;
        }
        rep(i, n) {
            cin >> b[i];
            kind[b[i]]++;
        }
        bool ok = true;
        rep(i, 5000 + 1) {
            if (kind[i] % 2 == 1) {
                ok = false;
                break;
            }
        }
        if (!ok) {
            bool success = true;
            rep(i, n) {
                if (a[i] != b[i]) {
                    if (i == n - 1 && a[0] == b[i]) continue;
                    if (a[i + 1] == b[i]) continue;
                    success = false;
                    break;
                }
            }
            print(success ? "Yes" : "No");
            continue;
        } else {
            print("No");
            continue;
        }
    }
}
