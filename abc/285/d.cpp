#include <bits/stdc++.h>

#include <cmath>

#if __has_include(<atcoder/all>)
#include <atcoder/all>
using namespace atcoder;
#endif

using namespace std;
using ll = long long;
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rep1(i, s, n) for (int i = s; i < n; i++)
#define all(vec) vec.begin(), vec.end()
using P = pair<int, int>;
using T = tuple<int, int, int>;
using graph = vector<vector<int>>;

int main() {
    int n;
    cin >> n;
    vector<string> from(n), to(n);
    rep(i, n) cin >> from[i] >> to[i];
    map<string, vector<string>> g;
    map<string, bool> visited;

    rep(i, n) {
        g[from[i]].push_back(to[i]);
    }

    for (auto p : g) {
        visited[p.first] = false;
    }

    for (auto p : g) {
        if (visited[p.first]) continue;
        visited[p.first] = true;
        queue<string> q;
        q.push(p.first);

        while (!q.empty()) {
            string v = q.front();
            q.pop();

            for (auto u : g[v]) {
                if (visited[u]) {
                    cout << "No" << endl;
                    return 0;
                }
                visited[u] = true;
                q.push(u);
            }
        }
    }
    cout << "Yes" << endl;
}
