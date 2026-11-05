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

const ll INF = 1e17;
vector<vector<ll>> d;
void floyd_init(int n) {
    d.assign(n + 1, vector<ll>(n + 1, INF));
    for (int i = 1; i <= n; i++) {
        d[i][i] = 0;
    }
}

void floyd(int n, vector<ll>& ans) {
    vector<int> x(n + 1);
    for (int i = 1; i <= n; i++) cin >> x[i];
    for (int c = n; c > 0; c--) {
        int k = x[c];
        for (int i = 1; i <= n; i++) {
            if (d[i][k] == INF) continue;
            for (int j = 1; j <= n; j++) {
                if (d[k][j] == INF) continue;
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
        ll sum = 0;
        for (int a = c; a <= n; a++) {
            for (int b = c; b <= n; b++) {
                sum += d[x[a]][x[b]];
            }
        }
        ans[c] = sum;

        // dbg_grid(d);
    }
}

void solve() {
    int n;
    cin >> n;
    floyd_init(n);
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> d[i][j];
        }
    }
    vector<ll> ans(n+1);
    floyd(n, ans);
    for (int i = 1; i <= n; i++) cout << ans[i] << ' ';
    cout << '\n';
    // dbg_grid(d);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}