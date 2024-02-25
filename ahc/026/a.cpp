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

struct Solver {
    int n, m;
    vector<vector<int>> b;
    vector<pair<int, int>> ans;

    Solver(int n, int m, vector<vector<int>> b) {
        this->n = n;
        this->m = m;
        this->b = b;
    }

    pair<int, int> get_index(int x) {
        rep(i, m) {
            rep(j, b[i].size()) {
                if (b[i][j] == x) {
                    return {i, j};
                }
            }
        }
        return {-1, -1};
    }

    void pick(int v) {
        auto [x, y] = get_index(v);
        b[x].erase(b[x].begin() + y);
        ans.push_back({v, 0});
    }

    int move(int v, int to) {
        auto [x, y] = get_index(v);
        // b[x]のy番目以降をsliceしてtoに移動
        vector<int> sliced(b[x].begin() + y, b[x].end());
        b[x].erase(b[x].begin() + y, b[x].end());
        b[to].insert(b[to].end(), sliced.begin(), sliced.end());
        ans.push_back({v, to + 1});
        return sliced.size();
    }

    pair<int, int> above(int x, int y) {
        if (b[x].size() - 1 > y) return {x, y + 1};
        return {-1, -1};
    }

    // <index, topの値(なければ-1)>
    vector<pair<int, int>> get_tops() {
        vector<pair<int, int>> res;
        rep(i, m) {
            if (b[i].size() > 0) {
                res.push_back({i, b[i].back()});
            } else {
                res.push_back({i, -1});
            }
        }
        return res;
    }

    void solve() {
        rep1(i, n) {
            auto [x, y] = get_index(i);
            pair<int, int> p = above(x, y);
            if (p.first != -1) {
                int v = b[p.first][p.second];
                vector<pair<int, int>> tops = get_tops();
                // p.firstを除いたtopsの中で最大のもの
                int max_top_index = -1;
                int max_top = -1;
                for (auto [i, top] : tops) {
                    if (top == -1) {
                        max_top_index = i;  // 空の山があればそこに優先的に移動
                        break;
                    }
                    if (top > max_top && i != p.first) {
                        max_top = top;
                        max_top_index = i;
                    }
                }
                if (max_top_index != -1) {
                    move(v, max_top_index);
                } else {
                    // max_top_indexが-1の場合
                    rep(i, m) {
                        if (i != p.first) {
                            move(v, i);
                            break;
                        }
                    }
                }
                pick(i);
            } else {
                pick(i);
            }
        }
    }

    void answer() {
        for (auto [x, y] : ans) {
            println(x, y);
        }
    }
};

int main() {
    int n, m;
    input(n, m);
    vector<vector<int>> b(m, vector<int>(n / m, 0));
    rep(i, m) rep(j, n / m) input(b[i][j]);

    Solver s = Solver(n, m, b);
    s.solve();
    s.answer();

    return 0;
}
