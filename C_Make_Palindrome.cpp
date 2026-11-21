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

void solve() {
    string a;
    cin >> a;
    vector<int> cnt(26);
    for (auto i : a) cnt[i - 'a']++;
    int n = a.size();
    sort(all(a));
    // cout << a << nl;
    string s = "";
    // dbg(cnt);
    for (int j = 0; j < 26; j++) {
        for (int i = 0; i < (cnt[j]) / 2; i++) {
            s += ('a' + j);
        }
        cnt[j] -= (2 * (cnt[j] / 2));
    }
    for (int j = 0; j < 26; j++) {
        if (cnt[j] && s.size() < ((n + 1) / 2)) s.push_back('a' + j);
    }
    sort(all(s));
    string ss = s;
    if (ss.size() + s.size() > n) ss.pop_back();
    reverse(all(ss));
    cout << s << ss << nl;
    // ;
    // int c = s.size() - 1;
    // // if (!(n & 1)) {
    //     c--;
    // }
    // for (int i =c;i>=0;i--){
    //     cout << s[i];
    // }
    // cout << '\n';
    // for (int i = 0;i<(n+1)/2;i++){
    //     cout << s[i];
    // }
    // for (int i = (n / 2)-1; i >= 0;i--){
    //     cout << s[i];
    // }

    // dbg(s);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    // cin>>t;
    while (t--) solve();
    return 0;
}