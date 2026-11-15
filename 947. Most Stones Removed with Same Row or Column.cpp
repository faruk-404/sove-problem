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

int removeStones(vector<vector<int>>& a) {
    DSU d(20010);
    vector<pair<int, int>> v;
    for (auto i : a) {
        v.emplace_back(i[0] + 1, i[1] + 10001);
    }

    for (auto [x, y] : v) {
        d.merge(x, y);
    }
    set<int> st;
    for (auto [x, y] : v) {
        // cout << d.find(x) << " " << d.find(y) << nl;
        st.insert(d.find(x));
        st.insert(d.find(y));
    }
    // dbg_grid(v);
    return a.size() - st.size();
}
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (auto& i : a)
        for (auto& j : i) cin >> j;
    // cout << a[2][1] << nl;
    cout << removeStones(a) << nl;
    dbg_grid(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}
