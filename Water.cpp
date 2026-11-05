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
    vector<pair<int, int>> a(n);
    for (int i = 0; i < n;i++){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(all(a));
    if(a[n-1].second>a[n-2].second){
        cout << a[n - 2].second << " " << a[n - 1].second << nl;
    }else{
        cout << a[n - 1].second << " " << a[n - 2].second << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}