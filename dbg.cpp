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
    int n, m;
    cin >> n >> m;
    int dp[3][2][4];
    // for(auto)
    vector<vector<pair<int,int>>> a(n, vector<pair<int,int>>(m, make_pair(0,3)));

    map<int, int> mp;
    for (int i = 0; i < n;i++){
        int c;
        cin >> c;
        mp[c] = c;
    }
    dbg_grid(mp);

    dbg(mp);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}