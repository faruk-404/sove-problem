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

void solve() {
    int n, m;
    cin >> n >> m;
    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++) cin >> a[i];
    DSU d(n);
    for (int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        d.merge(u, v);
    }
    vector<int> mm(n + 1,INT_MAX);
    for (int i = 1; i <= n;i++){
        int u = d.find(i);
        mm[u] = min(mm[u], a[i]);
    }
    ll ans = 0;
    for (int i = 1; i <= n;i++){
        if (i == d.find(i)) ans += mm[i];
    }
    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}