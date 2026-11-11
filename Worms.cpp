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
#define nf cout<<'\n'
#define ll long long
#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
const int N=3e5+5;


void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    cin >> a[0];
    for (int i = 1; i < n;i++){
        int x;
        cin >> x;
        a[i] = a[i - 1] + x;
    }
    int q;
    cin >> q;
    while(q--){
        int x;
        cin >> x;
        cout << lower_bound(a.begin(), a.end(), x) - a.begin()+1 << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}