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

#define cy cout << "YES\n"
#define cn cout << "NO\n"
#define all(v) v.begin(),v.end()
const int N=3e5+5;
#define ll long long
ll k;
ll f(int i,vector<int> &a,ll sum){
    if (i == -1 && sum == k) return 1;
    if (i <= -1) return 0;
    ll l= f(i - 1, a, sum + a[i]);
    ll r= f(i - 1, a, sum - a[i]);
    return l + r;
}
int findTargetSumWays(vector<int>& nums, int target) {
    k = target;
    return f(nums.size() - 1, nums, 0);
}
// [1,1,1,1,1], target = 3
void solve() {
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    cout << findTargetSumWays(a, x) << nl;

}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}