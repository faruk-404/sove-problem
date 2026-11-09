#include <iostream>
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

int f(int l, int r) {
    cout << "? " << l << " " << r << endl;
    int x;
    cin >> x;
    if (x == -1) exit(0);
    return x;
}

void solve() {
    int n;
    cin >> n;
    int k = f(1, n);
    if (k == 0 || k == n) {
        cout << "! NO" << endl;
        return;
    }
    int c = f(1, k);
    if (c == k) cout << "! NO" << endl;
    else cout << "! YES" << endl;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}