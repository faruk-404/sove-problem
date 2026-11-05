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

const int N=50+5;
vector<int> lp(N), pr;     // lp[x] = smallest prime factor
void linear_sieve(){
    for(int i=2;i<N;i++){
        if(!lp[i]){ lp[i]=i; pr.push_back(i); }
        for(int p:pr){
            if(p>lp[i] || (ll)i*p>=N) break;     // (ll) cast: i*p can overflow int
            lp[i*p]=p;
        }
    }
}
void solve(){
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    int ans = 0;
    for (int j = 0; j < n;j++){
        int cnt = 1;
        for (int i = j + 1; i < n;i++){
            if (a[i] % a[j] == 0) cnt++;
        }
        ans = max(ans, cnt);
    }
    cout << n - ans << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    linear_sieve();
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}