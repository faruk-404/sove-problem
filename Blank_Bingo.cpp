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
    vector<string> s(5);
    for (auto& i : s) cin >> i;
    int ans = 5;
    for (int i = 0; i < 5;i++){
        int cnt1 = 5,cnt2=5;
        for (int j = 0; j < 5;j++){
            if (s[i][j] == 'o') cnt1--;
            if (s[j][i] == 'o') cnt2--;
        }
        ans = min({ans, cnt1,cnt2});
    }
    int cnt = 5;
    for (int i = 0; i < 5;i++){
        if(s[i][i]=='o')cnt--;
    }
    ans = min(ans, cnt);
    reverse(all(s));
    cnt = 5;
    for (int i = 0; i < 5; i++) {
        if (s[i][i] == 'o') cnt--;
    }
    ans = min(ans, cnt);
    cout << ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}