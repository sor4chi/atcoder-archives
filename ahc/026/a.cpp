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

    vector<int> get_aboves(int x, int y) {
        // b[x]のy番目より上の値を取得
        vector<int> res;
        for (auto it = b[x].begin() + y + 1; it != b[x].end(); it++) {
            res.push_back(*it);
        }
        return res;
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
            // iを露出させるために上に積まれてるものをどうにか避ける
            if (p.first != -1) {
                int v = b[p.first][p.second];
                vector<int> aboves = get_aboves(x, y);
                reverse(aboves.begin(), aboves.end());
                int move_value = -1;
                rep(j, aboves.size()) {
                    int item = aboves[j];
                    vector<pair<int, int>> tops = get_tops();
                    sort(tops.begin(), tops.end(), [](auto a, auto b) { return a.second > b.second; });
                    if (move_value == -1) {
                        move_value = item;
                    } else {
                        // もしmove_valueよりもitemがおおきければmove_valueを更新
                        if (item > move_value) {
                            move_value = item;
                        } else {
                            // topsからmove_valueより大きくて最小のものを探す
                            int min_top = 1e9;
                            int min_top_index = -1;
                            for (auto [index, top] : tops) {
                                if (index == p.first) continue;  // 同じ列は無視
                                if(top == -1) {
                                    min_top = -1;
                                    min_top_index = index;
                                    break;
                                }
                                if (top > move_value && top < min_top) {
                                    min_top = top;
                                    min_top_index = index;
                                }
                            }
                            if (min_top_index != -1) {
                                // 見つかればそこに移動
                                move(move_value, min_top_index);
                            } else {
                                // 見つからなければ
                                // topsからmove_valueより小さいくて最大のものを探す
                                int max_top = -1;
                                int max_top_index = -1;
                                for (auto [index, top] : tops) {
                                    if (index == p.first) continue;  // 同じ列は無視
                                    if (top < move_value && top > max_top) {
                                        max_top = top;
                                        max_top_index = index;
                                    }
                                }
                                // 見つかればそこに移動
                                move(move_value, max_top_index);
                            }
                            move_value = item;
                        }
                    }
                    // もし最後の要素であれば
                    if (j == aboves.size() - 1) {
                        // topsからmove_valueより大きくて最小のものを探す
                        int min_top = 1e9;
                        int min_top_index = -1;
                        for (auto [index, top] : tops) {
                            if (index == p.first) continue;  // 同じ列は無視
                            if(top == -1) {
                                min_top = -1;
                                min_top_index = index;
                                break;
                            }
                            if (top > move_value && top < min_top) {
                                min_top = top;
                                min_top_index = index;
                            }
                        }
                        if (min_top_index != -1) {
                            // 見つかればそこに移動
                            move(move_value, min_top_index);
                        } else {
                            // 見つからなければ
                            // topsからmove_valueより小さいくて最大のものを探す
                            int max_top = -1;
                            int max_top_index = -1;
                            for (auto [index, top] : tops) {
                                if (index == p.first) continue;  // 同じ列は無視
                                if (top < move_value && top > max_top) {
                                    max_top = top;
                                    max_top_index = index;
                                }
                            }
                            // 見つかればそこに移動
                            move(move_value, max_top_index);
                        }
                    }
                }
            }
            pick(i);
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
