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
vector<pair<int, int>> strawberries;
chrono::system_clock::time_point start;
chrono::milliseconds time_limit(1900);

struct Solver {
    vector<array<int, 4>> ans;
    vector<array<int, 4>> best_ans;

    void answer() {
        println(best_ans.size());
        for (auto a : best_ans) {
            println(a[0], a[1], a[2], a[3]);
        }
    }

    void solve() {
        while (K--) {
            int p1x, p1y, p2x, p2y;
            p1x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            p1y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            p2x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            p2y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
            ans.push_back({p1x, p1y, p2x, p2y});
        }
        int min_loss = 1e9;
        bool first = true;
        while (true && chrono::system_clock::now() - start < time_limit) {
            if (first) {
                first = false;
            } else {
                int r = rng() % 3;
                if (r == 0) {
                    neighbor1();
                } else if (r == 1) {
                    neighbor2();
                } else {
                    neighbor3();
                }
            }
            map<vector<bool>, int> mp;
            for (auto s : strawberries) {
                vector<bool> v;
                for (auto [p1x, p1y, p2x, p2y] : ans) {
                    int a = p2y - p1y;
                    int b = p1x - p2x;
                    int c = p1x * (p1y - p2y) + p1y * (p2x - p1x);
                    int d = a * s.first + b * s.second + c;
                    v.push_back(d > 0);
                }
                mp[v]++;
            }
            map<int, int> mp2;
            for (auto [k, v] : mp) {
                mp2[v]++;
            }
            int loss = 0;
            rep(i, 10) {
                loss += abs(mp2[i + 1] - a[i]);
            }
            if (loss < min_loss) {
                min_loss = loss;
                best_ans = ans;
                answer();
            }
        }
    }

    // 近傍1 ansをランダムに1つ減らす
    void neighbor1() {
        if (ans.size() <= 1) return;
        int del_idx = rng() % ans.size();
        ans.erase(ans.begin() + del_idx);
    }

    // 近傍2 ansの1つの要素をランダムに1つ変更する
    void neighbor2() {
        int idx = rng() % ans.size();
        int p1x, p1y, p2x, p2y;
        p1x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        p1y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        p2x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        p2y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        ans[idx] = {p1x, p1y, p2x, p2y};
    }

    // 近傍3 ansをランダムに1つ追加する
    void neighbor3() {
        if (ans.size() >= K) return;
        int p1x, p1y, p2x, p2y;
        p1x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        p1y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        p2x = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        p2y = rng() % (2 * lpow(10, 4)) - lpow(10, 4);
        ans.push_back({p1x, p1y, p2x, p2y});
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);

    start = chrono::system_clock::now();
    input(N, K);
    rep(i, 10) input(a[i]);
    rep(i, N) {
        int x, y;
        input(x, y);
        strawberries.push_back({x, y});
    }

    Solver s;
    s.solve();

    return 0;
}
