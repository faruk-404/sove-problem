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

class Solution {
   public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> a;
        map<int, int> mp;
        for(int i=0;i<nums.size();i++){
            auto it = mp.find(target - nums[i]);
            if(it!=mp.end()){
                a.push_back(it->second);
                a.push_back(i);
                break;
            }
            mp[nums[i]] = i;
        }
        return a;
    }
};

// Input: nums = [2,7,11,15], target = 9
void solve(){

    int n;
    cin >> n;
    int t;
    cin >> t;
    vector<int> a(n);
    for (auto& i : a) cin >> i;
    dbg(n, t);
    dbg(a);
    Solution f;
    dbg(f.twoSum(a, t));
}
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t=1;
    // cin>>t;
    while(t--)solve();
    return 0;
}