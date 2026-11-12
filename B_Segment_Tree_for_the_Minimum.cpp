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

const int N = 1e6 + 5;
vector<ll> seg(N * 4);
vector<ll> a(N);

void build(int node, int l, int r) {
    if (l == r) {
        seg[node] = a[l];
        return;
    }
    int mid = l + (r - l) / 2;
    build(node * 2, l, mid);
    build(node * 2 + 1, mid + 1, r);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}
void update(int node, int l, int r, int idx, ll val) {
    if (idx < l || idx > r) return;
    if (l == r) {
        seg[node] = val;
        return;
    }
    int mid = l + (r - l) / 2;
    if (idx >= l && idx <= mid) update(node * 2, l, mid, idx, val);
    else update(node * 2 + 1, mid + 1, r, idx, val);
    seg[node] = min(seg[node * 2], seg[node * 2 + 1]);
}
ll query(int node, int l, int r, int ql, int qr) {
    if (r < ql || l > qr) return INT_MAX;
    if (l >= ql && r <= qr) return seg[node];
    int mid = l + (r - l) / 2;
    ll left = query(node * 2, l, mid, ql, qr);
    ll right = query(node * 2 + 1, mid + 1, r, ql, qr);
    return min(left, right);
}
void solve() {
    int n, q;
    cin >> n >> q;
    for (int i = 1; i <= n; i++) cin >> a[i];
    build(1, 1, n);
    while (q--) {
        int x, y, z;
        cin >> x >> y >> z;
        y++;
        if (x == 2) {
            cout << query(1, 1, n, y, z) << nl;

        } else {
            update(1, 1, n, y, z);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}