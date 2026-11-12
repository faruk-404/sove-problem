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

int shortestBridge(vector<vector<int>>& grid) {
    pair<ll, ll> st;
    ll n = grid.size();

    for (int i = 0; i < n; i++) {
        bool o = false;
        for (int j = 0; j < n; j++) {
           
            if (grid[i][j] == 1){
                st = make_pair(i, j);
                o = true;
                break;
            }
           
        }
        if (o) break;
    }
    
    vector<vector<ll>> a(n, vector<ll>(n, -1));
    
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 0) a[i][j] = 1;
        }
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (grid[i][j] == 1 && i && grid[i - 1][j] == 1) a[i][j] = 0;
            if (grid[i][j] == 1 && j && grid[i][j - 1] == 1) a[i][j] = 0;
        }
    }

    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (grid[i][j] == 1 && i != (n - 1) && grid[i + 1][j] == 1) a[i][j] = 0;
            if (grid[i][j] == 1 && j != (n - 1) && grid[i][j + 1] == 1) a[i][j] = 0;
        }
    }
    a[st.first][st.second] = 0;
    dbg_grid(a);
    ll mm = n * n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            ll x = (i && a[i - 1][j] != -1 ? a[i - 1][j] : 0);
            ll y = (j && a[i][j - 1] != -1 ? a[i][j - 1] : 0);
            if (a[i][j] == -1) {
                mm = min({mm, x, y});
            } else a[i][j] =min (a[i][j] , (min(x, y)+1));
        }
    }
    for (int i = n - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            ll x = (i != n - 1 && a[i + 1][j] != -1 ? a[i + 1][j] : 0);
            ll y = (j != n - 1 && a[i][j + 1] != -1 ? a[i][j + 1] : 0);
            if (a[i][j] == -1) {
                mm = min({mm, x, y});
            } else a[i][j] = a[i][j]+min(x, y);
        }
    }
    // cout << mm << nl;
    dbg_grid(a);
    // return grid.size();
    return mm;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<vector<int>> grid(n, vector<int>(m));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> grid[i][j];
        }
    }
    cout << shortestBridge(grid);
    dbg_grid(grid);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}