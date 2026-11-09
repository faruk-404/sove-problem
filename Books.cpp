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
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
// pb.order_of_key(x); x> cnt
// pb.find_by_order(idx); valu
template <typename T>
using pbds = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;
//                                               less_equal
// NOTE: erase by value is buggy with less_equal. Use: s.erase(s.find_by_order(s.order_of_key(x)));
// order_of_key(x) -> number of elements strictly < x ; find_by_order(k) -> iterator to k-th (0-indexed)

void solve() {
    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    sort(all(a));
    int sum = 0;
    pbds<int> pb;
    for (auto i : a) {
        sum += i;
        pb.insert(sum);
    }
    cout << pb.order_of_key(t + 1) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}