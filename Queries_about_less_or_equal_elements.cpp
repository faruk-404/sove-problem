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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
                         //pb.order_of_key(x); x> cnt
                         //pb.find_by_order(idx); valu
template<typename T> using pbds=tree<T,null_type,less_equal<T>,rb_tree_tag,tree_order_statistics_node_update>;
//                                               less_equal
// NOTE: erase by value is buggy with less_equal. Use: s.erase(s.find_by_order(s.order_of_key(x)));
// order_of_key(x) -> number of elements strictly < x ; find_by_order(k) -> iterator to k-th (0-indexed)

void solve(){
    int n, m;
    cin >> n >> m;
    pbds<int> pb;
    for (int i = 0;i<n;i++){
        int x;
        cin >> x;
        pb.insert(x);
    }
    for (int i = 0;i<m;i++){
        int x;
        cin >> x;
        cout << pb.order_of_key(x + 1) <<" ";
    }
    // dbg(pb);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}