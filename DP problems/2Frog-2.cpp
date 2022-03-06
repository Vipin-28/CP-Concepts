#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10, INF = 1e9+10;
int dp[N];


// int h[N];
// int func(int i){
//     int cost = INT_MAX;
//     for(int j = 1 ;j<=k;j++)
//     if(i-j>=0)
//          cost = min(cost, func(i-j) + abs(h[i] - h[i-j]));
//     return cost;
// }


int solve(vector<int>& heights, int n, int k){
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i = 2;i<n;i++){
        for(int j = 1;j<=k;j++){
            if(i-j<0)continue;
            dp[i] = min(dp[i], dp[i-j] + abs(heights[i] - heights[i-j]));
        }
    }
    return dp[n-1];
}

int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 0;i<n;i++)dp[i+1] = INF;
    vector<int> heights;
    for(int i = 0;i<n;i++){
        int h;
        cin>>h;
        heights.push_back(h);
    }
    int ans = solve(heights, n, k);
    // for(int i = 0;i<n;i++)cout<<dp[i]<<" ";
    // cout<<endl;
    cout<<ans<<endl;
    return 0;
}