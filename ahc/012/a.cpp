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

unsigned long rng() {
    static unsigned long x = 88172645463325252UL;
    x ^= x << 7;
    x ^= x >> 9;
    return x;
}

void answer() {
    cout << "end" << endl;
    cout.flush();
}

unsigned long lpow(unsigned long x, unsigned long n) {
    unsigned long ret = 1;
    while (n > 0) {
        if (n & 1) ret *= x;
        x *= x;
        n >>= 1;
    }
    return ret;
}

int N, K;
int a[10];
vector<pair<int, int>> xy;

struct Solver {
    void solve() {
        cout << K << endl;
        while (K--) {
            int p1x, p1y, p2x, p2y;
            p1x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            p1y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            p2x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            p2y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            cout << p1x << " " << p1y << " " << p2x << " " << p2y << endl;
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);

    input(N, K);
    rep(i, 10) input(a[i]);
    rep(i, N) {
        int x, y;
        input(x, y);
        xy.push_back({x, y});
    }

    Solver s;
    s.solve();

    return 0;
}
