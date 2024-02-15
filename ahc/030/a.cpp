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
#define rep(i, n) for (int i = 0; i < n; i++)
#define rep1(i, n) for (int i = 1; i <= n; i++)

struct Solver {
    int N;      // 10 <= N <= 20
    int M;      // 2 <= M <= 20
    float eps;  // 0.01 <= eps <= 0.2 (eps = 0.01k for some integer k)
    vector<vector<pair<int, int>>> mp;
    map<int, vector<pair<int, int>>> hit;
    int total = 0;

    Solver() {
        cin();
        init();
    }

   private:
    void cin() {
        input(N, M, eps);
        rep(i, M) {
            int d;
            input(d);
            total += d;
            vector<pair<int, int>> v(d);
            rep(j, d) {
                int a, b;
                input(a, b);
                v.push_back({a, b});
            }
            mp.push_back(v);
        }
    }

   private:
    void init() {
    }

   private:
    int question(vector<pair<int, int>>& v) {
        string s = "";
        for (auto p : v) {
            s += to_string(p.first) + " " + to_string(p.second) + " ";
        }
        s.pop_back();
        println('q', v.size(), s);
        int res;
        input(res);
        return res;
    }

   public:
    void answer() {
        int hit_cnt = 0;
        string s = "";
        for (auto p : hit) {
            hit_cnt += p.second.size();
            for (auto q : p.second) {
                s += to_string(q.first) + " " + to_string(q.second) + " ";
            }
        }
        s.pop_back();
        println('a', hit_cnt, s);
    }

   public:
    void solve() {
        int cnt = 0;
        rep(i, N) {
            rep(j, N) {
                vector<pair<int, int>> v = {{i, j}};
                int res = question(v);
                if (res >= 1) {
                    hit[res].push_back({i, j});
                    cnt += res;
                }
                if (cnt >= total) {
                    return;
                }
            }
        }
    }
};

int main() {
    // ios::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
    // cout << fixed << setprecision(15);

    Solver s;
    s.solve();
    s.answer();

    return 0;
}
