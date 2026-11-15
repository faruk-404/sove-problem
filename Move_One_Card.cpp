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
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (auto& i : a) cin >> i;
    for (auto& i : b) cin >> i;
    if (a == b) {
        cout << "Yes\n";
        return;
    }
    vector<int> c = a, d = b;
    sort(all(c));
    sort(all(d));
    // if (c != d) {
    //     cout << "No\n";
    //     return;
    // }
    int l = 0, r = n - 1;
    while (l < n && a[l] == b[l]) l++;
    while (r >= 0 && a[r] == b[r]) r--;
    if (l == n || r == -1) {
        cout << "Yes\n";
        return;
    }

    if(a[r]!=b[l] && a[l]!=b[r]){
        cout << "No\n";
        return;
    }
    // dbg(a[r ], b[l ], a[l], b[r]);
    if (a[l] == b[r]) {
        a.erase(a.begin() + l);
        b.erase(b.begin() + r);
        // dbg(a);
        // dbg(b);
        // for (int i = l; i < r;i++){
        //     // cout << b[i] << " " << a[i + 1] << nl;
        //     if(b[i]!=a[i+1]){
        //         cout << "No\n";
        //         return;
        //     }
        // }
    } else {
        a.erase(a.begin() + r);
        b.erase(b.begin() + l);

        // for (int i = l; i < r ; i++) {
        //     // cout << a[i] << " " << b[i + 1] << nl;
        //     if (a[i] != b[i + 1]) {
        //         cout << "No\n";
        //         return;
        //     }
        // }
    }
    // dbg(a);
    // dbg(b);
    if (a == b) cout << "Yes\n";
    else cout << "No\n";
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}