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
    for (auto& i : a) cin >> i;
    if(count(a.begin(),a.end(),1)==n){
        cout<<-1<<nl;
        return;
    }
    if(count(a.begin()+1,a.begin()+n-1,1)==n-2){
        cout << a[0] + a[n - 1] - 1 << nl;
        return;
    }
    cout << accumulate(a.begin(), a.end(), 0LL) - 1 << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}