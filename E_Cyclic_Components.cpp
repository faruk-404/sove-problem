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
    set<int> st, st1;
    int cnt = 0, cnt1 = 0;
    vector<pair<int, int>> a(m);
    vector<int> fq(n + 1), fpq(n + 1);
    for (auto& [i, j] : a) {
        cin >> i >> j;
        fq[i]++;
        fq[j]++;
    }
    DSU d(n);
    for (int i = 0; i < m; i++) {
        auto [u, v] = a[i];
        fpq[d.find(u)] = max({fpq[d.find(u)], fq[u], fq[v], fpq[d.find(v)]});
        fpq[d.find(v)] = max({fpq[d.find(u)], fq[u], fq[v], fpq[d.find(v)]});
        if (d.find(u) == d.find(v)) {
            if (st.count(d.find(u)) || fpq[d.find(u)] >= 3 || fpq[d.find(v)] >= 3) st1.insert(d.find(u));
            if (d.getsize(u) >= 3) st.insert(d.find(u));
        }
        d.merge(u, v);
        fpq[d.find(u)] = max({fpq[d.find(u)], fq[u], fq[v], fpq[d.find(v)]});
    }
    // dbg_grid(a);
    // dbg(fq);
    // dbg(fpq);
    cout << st.size() - st1.size() << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}