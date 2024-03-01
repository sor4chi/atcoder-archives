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

struct Ad {
    int x, y, r;
};

struct Rect {
    int x1, y1, x2, y2;
    bool operator==(const Rect& r) const {
        return x1 == r.x1 && y1 == r.y1 && x2 == r.x2 && y2 == r.y2;
    }
    bool overlap_with(const Rect& r) const {
        bool x_overlap = (x1 <= r.x1 && r.x1 <= x2) || (x1 <= r.x2 && r.x2 <= x2) || (r.x1 <= x1 && x1 <= r.x2) || (r.x1 <= x2 && x2 <= r.x2);
        bool y_overlap = (y1 <= r.y1 && r.y1 <= y2) || (y1 <= r.y2 && r.y2 <= y2) || (r.y1 <= y1 && y1 <= r.y2) || (r.y1 <= y2 && y2 <= r.y2);
        return x_overlap && y_overlap;
    }
};

int n;
vector<Ad> ads;

void answer(const vector<Rect>& ans) {
    for (auto r : ans) {
        println(r.x1, r.y1, r.x2, r.y2);
    }
}

unsigned long rng() {
    static unsigned long x = 88172645463325252UL;
    x ^= x << 7;
    x ^= x >> 9;
    return x;
}

double rnd() {
    return (double)rng() / (double)ULONG_MAX;
}

const map<char, pair<ll, ll>> d = {
    {'L', {0, -1}},
    {'R', {0, 1}},
    {'U', {-1, 0}},
    {'D', {1, 0}},
};

const char dir[4] = {'L', 'R', 'U', 'D'};

enum class Neighbor {
    EXPAND,
    RESET,
    SHRINK,
};

string stringify(Neighbor n) {
    if (n == Neighbor::EXPAND) return "EXPAND";
    if (n == Neighbor::SHRINK) return "SHRINK";
    if (n == Neighbor::RESET) return "RESET";
    return "UNKNOWN";
}

const int SIZE = 1e4;
double start_temp = 1e3;
double end_temp = 1e-3;

void print_report(const vector<Rect>& ans, ll score) {
    cerr << "score: " << score << endl;
    rep(i, n) {
        Rect a = ans[i];
        Ad ad = ads[i];
        int s = (a.x2 - a.x1) * (a.y2 - a.y1);
        cerr << a.x1 << " " << a.y1 << " " << a.x2 << " " << a.y2 << " " << s << endl;
        int diff = s - ad.r;
        cerr << "diff: " << diff << endl;
    }
}

struct Solver {
    vector<Rect> best_ans;

    ll evaluate(const vector<Rect>& ans) {
        long double score = 0.0;
        rep(i, n) {
            Ad ad = ads[i];
            Rect a = ans[i];
            double ad_x = ad.x + 0.5;
            double ad_y = ad.y + 0.5;
            if (a.x1 > ad_x || ad_x > a.x2 || a.y1 > ad_y || ad_y > a.y2) {
                score += 0;
            } else {
                int s = (a.x2 - a.x1) * (a.y2 - a.y1);
                double penalty = (1.0 - (double)min(ad.r, s) / (double)max(ad.r, s));
                score += 1.0 - penalty * penalty;
            }
        }
        score /= n;
        score *= 1e9;
        // round to nearest integer
        ll ret = (ll)(score + 0.5);
        return ret;
    }

    void solve(int tl = 1950) {
        for (auto ad : ads) {
            int x1 = ad.x;
            int y1 = ad.y;
            int x2 = ad.x + 1;
            int y2 = ad.y + 1;
            best_ans.push_back({x1, y1, x2, y2});
        }
        chrono::system_clock::time_point start = chrono::system_clock::now();
        chrono::system_clock::time_point time_limit = start + chrono::milliseconds(tl);
        ll best_score = 0;
        int iter = 0;
        int start_move_range = 30;
        int end_move_range = 30;

        while (chrono::system_clock::now() < time_limit) {
            double temp = start_temp + (end_temp - start_temp) * (double)(chrono::system_clock::now() - start).count() / (double)(time_limit - start).count();
            double progress = (double)(chrono::system_clock::now() - start).count() / (double)(time_limit - start).count();
            // だんだん減少していく, expを使って指数的に減少する
            // int move_range = end_move_range + (start_move_range - end_move_range) * exp(-100.0 * progress);
            int move_range = end_move_range + (start_move_range - end_move_range) * progress;
            iter++;
            // if (iter % 1000 == 0) println(move_range);

            // ========== ここから山登り操作 ==========
            vector<Rect> ans = best_ans;
            ll score = 0;
            int idx = rng() % n;
            Rect a = ans[idx];
            Ad ad = ads[idx];
            int s = (a.x2 - a.x1) * (a.y2 - a.y1);
            Neighbor selected;
            const vector<Neighbor> use_neighbors = {Neighbor::EXPAND, Neighbor::SHRINK};
            selected = use_neighbors[rng() % use_neighbors.size()];
            if (selected == Neighbor::EXPAND) {
                int try_left = 10;
                while (try_left--) {
                    int dx1 = 0, dx2 = 0, dy1 = 0, dy2 = 0;
                    int move_dir = rng() % 4;  // L, R, U, D
                    int expand_size = rng() % move_range + 1;
                    bool is_in_the_border = false;
                    if (move_dir == 0 && a.x1 - expand_size >= 0) {
                        dx1 = -expand_size;
                        is_in_the_border = true;
                    }
                    if (move_dir == 1 && a.x2 + expand_size < SIZE) {
                        dx2 = expand_size;
                        is_in_the_border = true;
                    }
                    if (move_dir == 2 && a.y1 - expand_size >= 0) {
                        dy1 = -expand_size;
                        is_in_the_border = true;
                    }
                    if (move_dir == 3 && a.y2 + expand_size < SIZE) {
                        dy2 = expand_size;
                        is_in_the_border = true;
                    }
                    if (!is_in_the_border) continue;
                    Rect new_a = a;
                    new_a.x1 += dx1;
                    new_a.x2 += dx2;
                    new_a.y1 += dy1;
                    new_a.y2 += dy2;
                    bool ok = true;
                    rep(i, n) {
                        if (i == idx) continue;
                        if (new_a.overlap_with(ans[i])) {
                            ok = false;
                            break;
                        }
                    }
                    if (!ok) continue;
                    ans[idx] = new_a;
                    break;
                }
                score = evaluate(ans);
            }
            if (selected == Neighbor::SHRINK) {
                int try_left = 10;
                while (try_left--) {
                    int dx1 = 0, dx2 = 0, dy1 = 0, dy2 = 0;
                    int move_dir = rng() % 4;  // L, R, U, D
                    int shrink_size = rng() % move_range + 1;
                    bool is_valid_shrink = false;
                    if (move_dir == 0 && a.x1 + shrink_size < a.x2) {
                        dx1 = shrink_size;
                        is_valid_shrink = true;
                    }
                    if (move_dir == 1 && a.x2 - shrink_size > a.x1) {
                        dx2 = -shrink_size;
                        is_valid_shrink = true;
                    }
                    if (move_dir == 2 && a.y1 + shrink_size < a.y2) {
                        dy1 = shrink_size;
                        is_valid_shrink = true;
                    }
                    if (move_dir == 3 && a.y2 - shrink_size > a.y1) {
                        dy2 = -shrink_size;
                        is_valid_shrink = true;
                    }
                    if (!is_valid_shrink) continue;
                    a.x1 += dx1;
                    a.x2 += dx2;
                    a.y1 += dy1;
                    a.y2 += dy2;
                    break;
                }
                score = evaluate(ans);
            }
            if (selected == Neighbor::RESET) {
                Ad ad = ads[idx];
                int x1 = ad.x;
                int y1 = ad.y;
                int x2 = x1 + 1;
                int y2 = y1 + 1;
                Rect new_a = {x1, y1, x2, y2};
                ans[idx] = new_a;
                score = evaluate(ans);
            }
            // ========== ここまで山登り操作 ==========

            int diff = score - best_score;

            if (diff > 0 || exp((double)diff / temp) > rnd()) {
                best_score = score;
                best_ans = ans;
            }
        }
    }
};

int main(int argc, char* argv[]) {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cout << fixed << setprecision(15);

    bool is_arg_contain_export = false;
    for (int i = 0; i < argc; i++) {
        if (string(argv[i]) == "--export") {
            is_arg_contain_export = true;
            break;
        }
    }

    input(n);
    rep(i, n) {
        int x, y, r;
        input(x, y, r);
        ads.push_back({x, y, r});
    }

    Solver s;
    s.solve(1950);
    int score = s.evaluate(s.best_ans);
    answer(s.best_ans);
    // print_report(s.best_ans, s.evaluate(s.best_ans));

    if (is_arg_contain_export)
        println("Score =", score);

    return 0;
}
