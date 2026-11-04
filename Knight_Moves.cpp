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

int n,m;
int dx[]={2,1,-1, 2,-2,-1,-2, 1 };
int dy[]={1,2, 2,-1,-1,-2, 1,-2 };

bool ok(ll x,ll y){
    return (x>=0 && y>=0 && x<n && y<m);
}

void bfs(pair<int,int> src, vector<vector<int>> &dist){
    dist.assign(n, vector<int>(m, -1));
    
    queue<pair<int,int>> q;
    dist[src.first][src.second] = 0;
    q.push(src);

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<8;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ok(nx,ny) && dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                q.push({nx,ny});
            }
        }
    }
}
void solve(){
    cin >> n >> m;
    int si, sj, ei, ej;
    cin >> si >> sj >> ei >> ej;
    vector<vector<int>> dist;
    bfs(make_pair(si, sj), dist);
    cout << dist[ei][ej] << nl;
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    cin>>t;
    while(t--)solve();
    return 0;
}