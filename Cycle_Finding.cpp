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

const ll INF = 1e18;
struct Edge {
    int u, v;
    ll w;
};
vector<Edge> edges;
// s=-1 hole sob vertex theke (virtual source), na hole s theke reachable cycle
vector<ll> bellman(int n, int s, bool& negcycle, vector<int>& cycle) {
    vector<ll> d(n + 1, (s == -1 ? 0 : INF));
    vector<int> par(n + 1, -1);
    if (s != -1) d[s] = 0;
    negcycle = false;
    cycle.clear();
    int x = -1;
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto& e : edges) {
            if (d[e.u] < INF && d[e.u] + e.w < d[e.v]) {
                d[e.v] = d[e.u] + e.w;
                par[e.v] = e.u;
                x = e.v;
            }
        }
       // if (x == -1) break;
    }
    if (x != -1) {  // n-th round-e-o relax hoyeche
        negcycle = true;
        for (int i = 0; i < n; i++) x = par[x];  // cycle er vitore ano
        for (int cur = x;1; cur = par[cur]) {
            cycle.push_back(cur);
            if (cur == x && cycle.size() > 1) break;
        }
        reverse(cycle.begin(), cycle.end());
    }
    // dbg(par);
    return d;
}

void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m;i++){
        int u, v;
       ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    vector<int> cycle;
    bool negcycle = false;
    vector<ll> dist = bellman(n, -1, negcycle, cycle);
    // dbg(cycle);
    // dbg(dist);
    if(negcycle){
        cy;
        for (auto i : cycle) cout << i << ' ';
        cout << '\n';
    }
    else cn;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}