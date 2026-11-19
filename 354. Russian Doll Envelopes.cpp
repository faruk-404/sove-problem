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
int prec(vector<pair<int, int>>& a) {
    int n = a.size();
    vector<int> dp(n, 1);
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (a[i].first < a[j].first && a[i].second < a[j].second && dp[j] < dp[i] + 1) {
                dp[j] = dp[i] + 1;
            }
        }
    }
    return *max_element(all(dp));
}
int maxEnvelopes(vector<vector<int>>& envelopes) {
    vector<pair<int, int>> a, b;
    for (auto i : envelopes) {
        a.push_back(make_pair(i[0], i[1]));
        b.push_back(make_pair(i[1], i[0]));
    }
    sort(all(a));
    sort(all(b));
    return max(prec(b), prec(a));
}
// Input: envelopes = [[5,4],[6,4],[6,7],[2,3]]
void solve() {
    int n;
    cin >> n;
    vector<vector<int>> a(n, vector<int>(2));
    for (auto& i : a)
        for (auto& j : i) cin >> j;
    cout << maxEnvelopes(a) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}