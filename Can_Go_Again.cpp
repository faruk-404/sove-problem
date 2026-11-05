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
vector<ll> bellman(int n, int s, bool& negcycle) {
    vector<ll> d(n + 1, (s == -1 ? 0 : INF));
    if (s != -1) d[s] = 0;
    negcycle = false;
    int x = -1;
    for (int i = 1; i <= n; i++) {
        x = -1;
        for (auto& e : edges) {
            if (d[e.u] < INF && d[e.u] + e.w < d[e.v]) {
                d[e.v] = d[e.u] + e.w;
                x = e.v;
            }
        }
        if (x == -1) break;
    }
    if (x != -1) { 
        negcycle = true;
    }
    return d;
}
void solve() {
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int u, v;
        ll w;
        cin >> u >> v >> w;
        edges.push_back({u, v, w});
    }
    bool negcycle = false;
    int scr, q;
    cin >> scr >> q;
    vector<int> d(q);
    for (auto& i : d) cin >> i;
    vector<ll> dist = bellman(n, scr, negcycle);
    if (negcycle) {
        cout << "Negative Cycle Detected\n";
        return;
    }
    for (auto i : d) {
        if (dist[i] == INF) cout << "Not Possible\n";
        else cout << dist[i] << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}  // #include <bits/stdc++.h>
// using namespace std;
// #ifdef LOCAL
// #include "debug.h"
// #else
// #define dbg(...)
// #define dbg_arr(...)
// #define dbg_range(...)
// #define dbg_grid(...)
// #define dbg_time(...)
// #endif

// #define nl '\n'
// #define nf cout << '\n'
// #define ll long long
// #define cy cout << "YES\n"
// #define cn cout << "NO\n"
// #define all(v) v.begin(), v.end()
// const int N = 3e5 + 5;

// const ll INF = 1e18;
// vector<vector<ll>> d;
// void floyd_init(int n) {
//     d.assign(n + 1, vector<ll>(n + 1, INF));
//     for (int i = 1; i <= n; i++) {
//         d[i][i] = 0;
//     }
// }
// void add_edge(int u, int v, ll w) {
//     if (w < d[u][v]) {
//         d[u][v] = w;
//     }
// }
// void floyd(int n) {
//     for (int k = 1; k <= n; k++)
//         for (int i = 1; i <= n; i++) {
//             if (d[i][k] == INF) continue;
//             for (int j = 1; j <= n; j++) {
//                 if (d[k][j] == INF) continue;
//                 if (d[i][k] + d[k][j] < d[i][j]) {
//                     d[i][j] = d[i][k] + d[k][j];
//                 }
//             }
//         }
// }

// void solve() {
//     int n, m;
//     cin >> n >> m;
//     floyd_init(n);
//     for (int i = 0; i < m; i++) {
//         int a, b;
//         ll w;
//         cin >> a >> b >> w;
//         add_edge(a, b, w);
//     }
//     floyd(n);
//     int scr, q;
//     cin >> scr >> q;
//     vector<int> dist(q);
//     for (auto& i : dist) cin >> i;
//     for (int i = 1; i <= n; i++) {
//         if (d[i][i] < 0) {
//             cout << "Negative Cycle Detected\n";
//             return;
//         }
//     }
//     for (auto i : dist) {
//         if (d[scr][i] == INF) cout << "Not Possible\n";
//         else cout << d[scr][i] << nl;
//     }
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t = 1;
//     // cin >> t;
//     while (t--) solve();
//     return 0;
// }