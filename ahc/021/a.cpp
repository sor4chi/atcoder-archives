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

int PYRAMID_SIZE = 30;
int MAX_ITER = 10000;

typedef pair<int, int> Coordinate;

struct Ball {
    int value;
};

struct Swap {
    Coordinate a;
    Coordinate b;
};

struct Solver {
    map<Coordinate, Ball> pyramid;
    vector<Swap> swaps;
    time_t start = clock();

    Solver() {
        cin();
        init();
    }

    void cin() {
        rep(i, PYRAMID_SIZE) {
            rep(j, i + 1) {
                int value;
                input(value);
                pyramid[{i, j}] = {value};
            }
        }
    }

    void init() {
    }

    void solve() {
        int cnt = 0;
        while (cnt++ < MAX_ITER && clock() - start < 1.9 * CLOCKS_PER_SEC) {
            for (int i = PYRAMID_SIZE - 1; i > 0; i--) {
                rep(j, i + 1) {
                    int me = pyramid[{i, j}].value;
                    int lb = -1, rb = -1;
                    if (j > 0) {
                        lb = pyramid[{i - 1, j - 1}].value;
                    }
                    if (j < i) {
                        rb = pyramid[{i - 1, j}].value;
                    }
                    if (lb < me && rb < me) {
                        continue;
                    }
                    if (lb > rb) {
                        swap(pyramid[{i, j}], pyramid[{i - 1, j - 1}]);
                        swaps.push_back({{i, j}, {i - 1, j - 1}});
                    } else {
                        swap(pyramid[{i, j}], pyramid[{i - 1, j}]);
                        swaps.push_back({{i, j}, {i - 1, j}});
                    }
                }
            }
        }
    }

    void answer() {
        println(swaps.size());
        for (auto swap : swaps) {
            println(swap.a.first, swap.a.second, swap.b.first, swap.b.second);
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);

    Solver s;
    s.solve();
    s.answer();

    return 0;
}
