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
    string s;
    cin >> s;
    int k;
    cin >> k;
    // string t = s;
    // for (int i = 0, j = 0; i < s.size() && j < k; i++) {
    //     if (t[i] > 1) {
    //         t[i] = '#';
    //         j++;
    //     }
    // }
    // int cnt = 0, cnt1 = -1, pos = -1, pos1 = 0;
    // int kk = k - cnt1;
    // for (int i = 0; i < s.size() && cnt <= k; i++) {
    //     if (s[i] >= '1') {
    //         cnt++;
    //     }
    //     if (s[i] == '0') {
    //         cnt1 = cnt;
    //         pos = i;
    //     }
    // }
    // for(int i=pos+1;i<s.size()&& kk <=k;i++){
    //     if (s[i] > s[i + 1]) {
    //         s[i] = '#';
    //         kk++;
    //     }
    // }
    // dbg(cnt1, pos, cnt,s);
    // for (int i =0,j=0; i < s.size() && j< k; i++) {
    //     if (s[i] > s[i + 1]) {
    //         s[i] = '#';
    //         j++;
    //     }
    // }
    // for(int i=0)

    vector<int> a;
    int n = s.size();
    for (auto i : s) {
        a.push_back(i - '0');
    }
    vector<int> b = a;
    int t = k;
    priority_queue<pair<int, int>> pq;
    for (int i = 0; i < n; i++) {
        pq.push(make_pair(a[i], i));
        while (!pq.empty() && t && a[i] < pq.top().first) {
            b[pq.top().second] = -1;
            pq.pop();
            t--;
        }
    }
    for (int i = n - 1; i >= 0 && t; i--) {
        if (b[i] != -1) {
            t--;
            b[i] = -1;
        }
    }
    for (auto& i : b) {
        if (i > 0) break;
        i = -1;
    }

    // dbg(pq);
    // dbg(a);
    // dbg(b);
    // dbg(s);
    bool o = true;
    for (auto i : b) {
        if (i != -1) {
            cout << i;
            o = false;
        }
    }
    if (o) cout << 0;
    cout << '\n';
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t = 1;
    cin >> t;
    while (t--) solve();
    return 0;
}