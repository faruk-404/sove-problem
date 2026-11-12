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

struct DSU{
    int c;
    vector<int> par,rnk,siz;
    DSU(int n):par(n+1),rnk(n+1),siz(n+1,1){
        c=n;
        for(int i=1;i<=n;i++) par[i]=i;
    }
    int find(int i){
        if(i==par[i])return i;
        return par[i]=find(par[i]);
    }

    bool same(int u,int v){
        return find(u)==find(v);
    }
    int getsize(int u){
        return siz[find(u)];
    }
    int cnt(){
        return c;
    }
    void merge(int u,int v){
        u=find(u),v=find(v);
        if(u==v)return;
        else c--;
        if(rnk[u]>rnk[v])swap(u,v);
        else if(rnk[u]==rnk[v]) rnk[v]++;
        par[u]=v;
        siz[v]+=siz[u];
    }
};
void solve(){
    int n;
    cin >> n;
    DSU d(n);
    vector<pair<int, int>> a,b;
    for (int i = 0; i < n - 1;i++){
        int u, v;
        cin >> u >> v;
        if(d.find(u)==d.find(v)){
            a.push_back(make_pair(u, v));
        }
        d.merge(u, v);
    }
    cout << a.size() << nl;
    if (!a.size()) return;
    for (int i = 2; i <= n;i++){
        if (d.find(1) != d.find(i)) b.push_back(make_pair(1, i));
        d.merge(1, i);
    }
    for (int i = 0; i < a.size();i++){
        cout << a[i].first << " " << a[i].second << " " << b[i].first << " " << b[i].second << nl;
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}