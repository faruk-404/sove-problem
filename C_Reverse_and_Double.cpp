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
const int N = 3e5 + 5;

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<int> mx(n - 1);
    int p = 0;
    for (int i = 0; i + 1 < n; i++) {
        mx[i] = abs(a[i + 1] - a[i]);
        if (mx[i] > mx[p]) p = i;
    }
    int mxx = mx[p];
    vector<int> pre(n + 2, 0), suf(n + 2, 0);
    for (int i = 1; i < n; i++) pre[i] = max(pre[i - 1], mx[i - 1]);
    for (int i = n - 2; i >= 0; i--) suf[i] = max(suf[i + 1], mx[i]);
    int ans = mxx;
    int l = p + 1;
    int yy = 0;
    for (int r = l; r < n; r++) {
        if (r > l) yy = max(yy, 2 * mx[r - 1]);
        int cc = max({pre[l - 1], yy, suf[r + 1]});
        cc = max(cc, abs(a[l - 1] - 2 * a[r]));
        if (r < n - 1) cc = max(cc, abs(2 * a[l] - a[r + 1]));
        ans = min(ans, cc);
    }
    int r = p;
    int yyy = 0;
    for (int l = p; l >= 0; l--) {
        if (l < p) yyy = max(yyy, 2 * mx[l]);
        int cc = max({(l >= 1 ? pre[l - 1] : 0), yyy, suf[r + 1]});
        if (l > 0) cc = max(cc, abs(a[l - 1] - 2 * a[r]));
        cc = max(cc, abs(2 * a[l] - a[r + 1]));
        ans = min(ans, cc);
    }
    cout << ans << nl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}