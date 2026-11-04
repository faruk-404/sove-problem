#include <bits/stdc++.h>
using namespace std;
#ifdef LOCAL
#include "debug.h"
#else
#define dbg(...)
#define dbg_arr(...)
#define dbg_range(...)
#define dbg_grid(...)
#define dbg_time(...)
#endif

#define nl '\n'
#define nf cout << '\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(), v.end()
const int N = 3e5 + 5;

struct DSU {
    int c;
    vector<int> par, rnk, siz;
    DSU(int n) : par(n + 1), rnk(n + 1), siz(n + 1, 1) {
        c = n;
        for (int i = 1; i <= n; i++) par[i] = i;
    }
    int find(int i) {
        if (i == par[i]) return i;
        return par[i] = find(par[i]);
    }

    bool same(int u, int v) {
        return find(u) == find(v);
    }
    int getsize(ll u) {
        return siz[find(u)];
    }
    int cnt() {
        return c;
    }
    void merge(int u, int v) {
        u = find(u), v = find(v);
        if (u == v) return;
        else c--;
        if (rnk[u] > rnk[v]) swap(u, v);
        else if (rnk[u] == rnk[v]) rnk[v]++;
        par[u] = v;
        siz[v] += siz[u];
    }
};

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}

void solve() {
    cin >> n >> m;
    vector<string> s(n);
    for (auto& i : s) cin >> i;
    vector<vector<int>> arr(n, vector<int>(m));
    int t = 1;
    for (auto& i : arr)
        for (auto& j : i) j = t++;
    DSU d(n * m);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            for (int ii = 0; ii < 4; ii++) {
                int nx = i + dx[ii];
                int ny = j + dy[ii];
                if (ok(nx, ny) && s[nx][ny] != '-' && s[i][j]!='-') {
                    d.merge(arr[i][j], arr[nx][ny]);
                }
            }
        }
    }
    int ans = INT_MAX;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] != '-') {
                ans = min(d.getsize(arr[i][j]), ans);

            }
        }
    }
    if (ans == INT_MAX) cout << -1 << nl;
    else cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}