#include<bits/stdc++.h>
#define ll long long
#define mod 1e9 + 7
using namespace std;
void helper(vector<vector<int>>& subs, vector<int>& sub, int i,  int n, vector<int>& nums){
    if(i==n){
        subs.push_back(sub);
        return;
    }
    sub.push_back(nums[i]);
    helper(subs, sub, i+1, n, nums);
    sub.pop_back();
    helper(subs, sub, i+1, n, nums);
}
void solve(){
    int n; cin>>n;
    vector<int> nums(n);
    for(int i = 0;i<n;i++)cin>>nums[i];

    vector<vector<int>> subs;
    vector<int> sub;
    helper(subs, sub, 0, n, nums);
    for(auto e: subs){
        for(auto ee: e){
            cout<<ee<<" ";
        }
        cout<<endl;
    }
}
int main(){
    cin.tie(), cout.tie(0);
    ios::sync_with_stdio(false);
    int t = 1;
    //cin>>t;
    while(t--)
        solve();
    return 0;
}