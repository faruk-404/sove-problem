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
    string s;
    cin >> s;
    vector<int> a;
    for (auto i : s) a.push_back(i - '0');
    int re = 0;
    for (int i = 0; i < a.size();i++){
        re *= 10;
        re += a[i];
        re %= 7;
        dbg(re);
    }
    if (re == 0) cy;
    else cn;
    dbg(re);
    dbg(a);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}