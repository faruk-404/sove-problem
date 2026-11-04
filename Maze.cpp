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

int n, m;
int dx[] = {0, 0, -1, 1};
int dy[] = {1, -1, 0, 0};

bool ok(int x, int y) {
    return (x >= 0 && y >= 0 && x < n && y < m);
}
void bfs(pair<int, int> src, vector<string>& gid,
         vector<vector<int>>& dist, vector<vector<pair<int, int>>>& parent) {
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int, int>>(m, {-1, -1}));

    queue<pair<int, int>> q;
    dist[src.first][src.second] = 0;
    q.push(src);

    while (!q.empty()) {
        auto [x, y] = q.front();
        q.pop();
        for (ll i = 0; i < 4; i++) {
            ll nx = x + dx[i];
            ll ny = y + dy[i];
            if (ok(nx, ny) && gid[nx][ny] != '#' && dist[nx][ny] == -1) {
                dist[nx][ny] = dist[x][y] + 1;
                parent[nx][ny] = {x, y};
                q.push({nx, ny});
            }
        }
    }
}

void solve() {
    cin >> n >> m;
    vector<string> s(n);
    for (auto& i : s) cin >> i;
    int si, sj, ei, ej;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (s[i][j] == 'R') {
                si = i;
                sj = j;
            } else if (s[i][j] == 'D') {
                ei = i;
                ej = j;
            }
        }
    }
    vector<vector<int>> dist;
    vector<vector<pair<int, int>>> parent;
    bfs(make_pair(si, sj), s, dist, parent);
    if (dist[ei][ej] == -1) {
        for (auto i : s) cout << i << nl;
        return;
    }

    pair<int, int> st = parent[ei][ej];
    while ((st.first != -1 && st.second != -1)) {
        s[st.first][st.second] = 'X';
        st = parent[st.first][st.second];
    }
    s[si][sj] = 'R';
    for (auto i : s) cout << i << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}