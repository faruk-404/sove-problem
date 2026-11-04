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
const int N = 3e5 + 5;

int n,m;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};

bool ok(int x,int y){
    return (x>=0 && y>=0 && x<n && y<m);
}

char out(int dx_,int dy_){
    if(dx_==-1 && dy_==0) return 'U';
    if(dx_==1  && dy_==0) return 'D';
    if(dx_==0  && dy_==-1) return 'L';
    if(dx_==0  && dy_==1)  return 'R';
    return '?';
}

void bfs(pair<int,int> src, vector<string> &gid,vector<vector<int>> &dist, vector<vector<pair<int,int>>> &parent){
    dist.assign(n, vector<int>(m, -1));
    parent.assign(n, vector<pair<int,int>>(m, {-1,-1}));

    queue<pair<int,int>> q;
    dist[src.first][src.second] = 0;
    q.push(src);

    while(!q.empty()){
        auto [x,y]=q.front();
        q.pop();
        for(int i=0;i<4;i++){
            int nx=x+dx[i];
            int ny=y+dy[i];
            if(ok(nx,ny) && gid[nx][ny]!='-' && dist[nx][ny]==-1){
                dist[nx][ny]=dist[x][y]+1;
                parent[nx][ny]={x,y};
                q.push({nx,ny});
            }
        }
    }
}

void solve(){
    cin >> n >> m;
    vector<string> s(n);
    for (auto& i : s) cin >> i;
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    if(s[si][sj]=='-'|| s[di][dj]=='-'){
        cn;
        return;
    }
    // dbg(s);

    vector<vector<int>> dist;
    vector<vector<pair<int,int>>> parent(n,vector<pair<int,int>>(m,{-1,-1}));
    bfs(make_pair(si, sj), s, dist, parent);
    if (dist[di][dj] == -1) cn;
    else cy;
    // dbg(dist);
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}