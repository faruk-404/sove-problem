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
class Solution {
   public:
    int longestConsecutive(vector<int>& nums) {
        vector<int> a;
        for (auto i : nums) a.push_back(i);
        sort(all(a));
        int cnt = 1;
        int mx = 0;
        a.erase(unique(a.begin(), a.end()), a.end());
        for (int i = 1; i < a.size(); i++) {
            if (a[i] == a[i - 1] + 1) {
                cnt++;
            } else {
                mx = max(mx, cnt);
                cnt = 1;
            }
        }
        mx = max(mx, cnt);
        return min(mx, (int)nums.size());
    }
};

// Input: nums = [100,4,200,1,3,2]
// Input : nums = [ 0, 3, 7, 2, 5, 8, 4, 6, 0, 1 ]
void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    Solution d;
    cout << d.longestConsecutive(a) << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}