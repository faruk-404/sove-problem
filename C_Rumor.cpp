
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
    int c,n;
    vector<int> par,rnk,siz,mm;
    DSU(int n):n(n),par(n+1),rnk(n+1),siz(n+1,1),mm(n+1,INT_MAX){
        c=n;
        for(int i=1;i<=n;i++) par[i]=i;
    }
    void esial(vector<int>&a){
        for(int i=0;i<n;i++)mm[i] = a[i];
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
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    vector<bool> o(n, true);
    ll ans = 0;
    while(q--){
        int u, v;
        cin >> u >> v;
        int mm = INT_MAX;
        for (int i = u - 1; i < v;i++){
            mm = min(mm, a[i]);
        }
    }
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}// #include <bits/stdc++.h>
// using namespace std;
// #ifdef LOCAL
// #include "debug.h"
// #else
// #define dbg(...)
// #define dbg_arr(...)
// #define dbg_range(...)
// #define dbg_grid(...)
// #define dbg_time(...)
// #endif


// #define nl '\n'
// #define nf cout<<'\n'
// #define ll long long
// #define cy cout << "YES\n"
// #define cn cout << "NO\n"
// #define all(v) v.begin(),v.end()
// const int N=1e6+5;
// vector<ll> seg(N*4);
// vector<ll> a(N);

// void build(int node,int l,int r){
//     if(l==r){
//         seg[node]=a[l];
//         return;
//     }
//     int mid=l+(r-l)/2;
//     build(node*2,l,mid);
//     build(node*2+1,mid+1,r);
//     seg[node]=min(seg[node*2],seg[node*2+1]);
// }
// // void update(int node,int l,int r,int idx,ll val){
// //     if(idx < l || idx > r) return;
// //     if(l==r){
// //         seg[node]=val;
// //         return;
// //     }
// //     int mid=l+(r-l)/2;
// //     if(idx>=l && idx<=mid)update(node*2,l,mid,idx,val);
// //     else update(node*2+1,mid+1,r,idx,val);
// //     seg[node]=seg[node*2]+seg[node*2+1];
// // }
// ll query(int node,int l,int r,int ql,int qr){
//     if(r<ql || l>qr) return LLONG_MAX;
//     if(l>=ql && r<=qr)return seg[node];
//     int mid=l+(r-l)/2;
//     ll left=query(node*2,l,mid,ql,qr);
//     ll right=query(node*2+1,mid+1,r,ql,qr);
//     return min(left,right);
// }

// void solve(){
//     int n, q;
//     cin >> n >> q;
//     ll sum = 0;
//     for (int i = 1; i <= n; i++) cin >> a[i];
//     build(1,1,n);
//     cout << query(1, 1, n, 1, 4) << nl;
// }
// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);
//     int t=1;
//     // cin>>t;
//     while(t--)solve();
//     return 0;
// }