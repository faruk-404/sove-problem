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
    int getsize(int u) {
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

int minCostConnectPoints(vector<vector<int>>& points) {
    vector<array<int, 3>> a;
    int nd = 1;
    for (auto i : points) a.push_back({nd++, i[0], i[1]});
    int n = a.size();
    // dbg_grid(a);
    vector<array<int, 3>> edges;
    // {w,u,v}  (w big -> ll)
    // edges.push_back({w,u,v});

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            edges.push_back({(abs(a[i][1] - a[j][1]) + abs(a[i][2] - a[j][2])), a[i][0], a[j][0]});
            edges.push_back({(abs(a[i][1] - a[j][1]) + abs(a[i][2] - a[j][2])), a[j][0], a[i][0]});
        }
    }
    sort(all(edges));
    dbg_grid(edges);
    DSU d(n);
    int cost = 0;
    int used = 0;
    for (auto [w, u, v] : edges) {
        if (d.same(u, v)) continue;
        d.merge(u, v);
        cost += w;
        used++;
    }
    // MST exists iff used==n-1
    return cost;
}

void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (auto& i : a)
        for (auto& j : i) cin >> j;
    cout << minCostConnectPoints(a) << nl;

    // dbg_grid(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}