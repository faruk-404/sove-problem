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
#define all(v) v.rbegin(), v.rend()
const int N = 3e5 + 5;


mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
int my_rand(int l, int r) {
    return uniform_int_distribution<int>(l, r)(rng);
}
int f(int i, vector<int>& a, int& s) {
    if (i < 0) return 0;
    int mm = INT_MAX;
    mm = min(mm, abs((f(i - 1, a, s) + a[i]) - s));
    mm = min(mm, abs(f(i - 1, a, s) - s));
    return mm;
}

void solve() {
    int n = 5;
    cin >> n;
    vector<int> a(n);
    for (auto& i : a)  cin>>i;
    int sum = accumulate(all(a), 0);
    int s = sum / 2;
    cout << f(n - 1, a, s) << nl;
    s = sum - s;
    cout << f(n - 1, a, s) << nl;

    // vs

    sort(all(a));
    for (int i = 0; i < n; i++) {
        if (sum > s) {
            sum -= a[i];
        } else break;
    }
    cout << abs(sum - (accumulate(all(a),0)-s) )<< nl;
    sum = accumulate(all(a), 0);
    s = sum / 2;
    for (int i = 0; i < n; i++) {
        if (sum > s) {
            sum -= a[i];
        } else break;
    }
    cout << abs(sum - s) << nl;

    //=====

    int S = accumulate(a.begin(), a.end(), 0);

    vector<bool> dp(S / 2 + 1, false);
    dp[0] = true;

    for (int x : a) {
        for (int j = S / 2; j >= x; j--) {  // পেছন থেকে, যাতে একই element দুইবার না নেওয়া হয়
            if (dp[j - x]) dp[j] = true;
        }
    }

    dbg(a);
    
    for (int j = S / 2; j >= 0; j--) {
        if (dp[j]) {
            cout << S - 2 * j << nl;
            return;
        }
    }
    
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}