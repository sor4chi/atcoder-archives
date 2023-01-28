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
#define rep1(i, n) for (ll i = 1; i <= n; i++)

int main() {
    int n, m;
    input(n, m);
    if (n - m != 1) {
        print("No");
        return 0;
    }
    vector<vector<int>> g(n + 1);
    queue<int> q;
    vector<int> visited(n + 1, 0);

    rep(i, m) {
        int a, b;
        input(a, b);
        g[a].push_back(b);
        g[b].push_back(a);
    }

    int path = 0, edge = 0;
    for (int i = 1; i <= n; i++) {
        if (g[i].size() == 2) {
            path++;
        } else if (g[i].size() == 1) {
            edge++;
        }
    }

    if (!(n - path == 2 && edge == 2)) {
        print("No");
        return 0;
    }

    q.push(1);
    visited[1] = 1;
    while (!q.empty()) {
        int u = q.front();
        q.pop();
        for (auto v : g[u]) {
            if (visited[v] == 0) {
                visited[v] = 1;
                q.push(v);
            }
        }
    }

    rep1(i, n) {
        if (visited[i] == 0) {
            print("No");
            return 0;
        }
    }

    print("Yes");
    return 0;
}
