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
const int p1 = 137, mod1 = 127657753, p2 = 277, mod2 = 987654319;
const int N = 1e6 + 9;
pair<int, int> pw[N], ipw[N];
bool ok[1000004];

ll bigmod(ll a, ll b, ll mod) {
    ll r = 1;
    a %= mod;
    while (b > 0) {
        if (b & 1) r = r * a % mod;
        a = a * a % mod;
        b >>= 1;
    }
    return r;
}

void prec() {  // O(n)
    pw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        pw[i].first = 1LL * pw[i - 1].first * p1 % mod1;
        pw[i].second = 1LL * pw[i - 1].second * p2 % mod2;
    }
    ll ip1 = bigmod(p1, mod1 - 2, mod1);
    ll ip2 = bigmod(p2, mod2 - 2, mod2);
    ipw[0] = {1, 1};
    for (int i = 1; i < N; i++) {
        ipw[i].first = 1LL * ipw[i - 1].first * ip1 % mod1;
        ipw[i].second = 1LL * ipw[i - 1].second * ip2 % mod2;
    }
}

pair<int, int> string_hash(string s) {  // O(n)
    int n = s.size();
    pair<int, int> hs({0, 0});
    for (int i = 0; i < n; i++) {
        hs.first = (hs.first + 1LL * s[i] * pw[i].first) % mod1;
        hs.second = (hs.second + 1LL * s[i] * pw[i].second) % mod2;
    }
    return hs;
}

pair<int, int> f(pair<int, int> hs, int &i, string &s, char &c) {
    hs.first = ((hs.first - 1LL * s[i] * pw[i].first) + mod1) % mod1;
    hs.second = ((hs.second - 1LL * s[i] * pw[i].second) + mod2) % mod2;
    hs.first = (hs.first + 1LL * c * pw[i].first) % mod1;
    hs.second = (hs.second + 1LL * c * pw[i].second) % mod2;
    return hs;
}

void solve() {
    int n, m;
    cin >> n >> m;
    vector<string> ss(n);
    for (auto& i : ss) cin >> i;
    set<pair<int, int>> cnt;

    memset(ok, false, sizeof(ok));

    for (auto& s : ss) {
        ok[s.size()] = true;
        pair<int, int> hs = string_hash(s);
        for (int i = 0; i < s.size(); i++) {
            for (auto c : {'a', 'b', 'c'}) {
                if(c==s[i])continue;
                cnt.insert(f(hs, i, s, c));
            }
        }
    }

    // dbg_grid(cnt);
    for (int i = 0; i < m; i++) {
        string s;
        cin >> s;
        if (!ok[s.size()]) {
            cn;
            continue;
        }
        pair<int, int> hss = string_hash(s);
        if (cnt.count(hss)) cy;
        else cn;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    prec();
    int t = 1;
    // cin >> t;
    while (t--) solve();
    return 0;
}