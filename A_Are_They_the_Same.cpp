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

void solve() {
    int n, k;
    cin >> n >> k;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    int od = 0, ev = 0;
    for (auto& i : a)
        if (i & 1) od++;
        else ev++;
    int od1 = 0, ev1 = 0;
    for (auto i : b)
        if (i & 1) od1++;
        else ev1++;
    if (od == od1) {
        cy;
        return;
    }
    if (od1 < od) {
        if (!(k & 1)) {
            cy;
            return;
        } else cn;
    } else if (ev1 < ev) {
        if (k & 1) {
            cy;
        } else cn;
    }
    // dbg(od, ev,od1,ev1);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}