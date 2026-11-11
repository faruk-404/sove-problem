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
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    map<int, int> mp1, mp2;
    for (int i = 0; i < n; i++) {
        auto it = mp1.upper_bound(-a[i]);
        cout << ((it == mp1.end()) ? 0 : it->second) << " ";
       
        while (true) {
            it = mp2.lower_bound(a[i]);
            if(it==mp2.end())break;
            mp2.erase( it);
            mp1.erase(-(it->first));
        }
        mp1[-a[i]] = i + 1;
        mp2[a[i]] = i + 1;
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