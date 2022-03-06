#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N];

// int h[N];
// int func(int i){
//     int cost = INT_MAX;
//     // way 1
//     cost = min(cost, func(i-1) + abs(h[i] - h[i-1]));
//     // way 2
//     cost = min(cost, func(i-2) + abs(h[i] - h[i-2]));
//     return cost;
// }

int solve(vector<int>& heights, int n){
    dp[0] = 0;
    dp[1] = abs(heights[1] - heights[0]);
    for(int i = 2;i<n;i++){
        dp[i] = min(dp[i-1] + abs(heights[i] - heights[i-1]), dp[i-2] + abs(heights[i-2] - heights[i]));
    }
    return dp[n-1];
}

int main(){
    int n;
    cin>>n;
    vector<int> heights;
    for(int i = 0;i<n;i++){
        int h;
        cin>>h;
        heights.push_back(h);
    }
    cout<<solve(heights, n)<<endl;
    return 0;
}