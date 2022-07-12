#include<bits/stdc++.h>
using namespace std;

int wt[101], val[101];
long long dp[101][100001];

long long solve(int n, int W){
    if(n == 0 || W == 0)return 0;
    if(dp[n][W] != -1)return dp[n][W];

    if(wt[n-1] <= W)
        return dp[n][W] = max(val[n-1] + solve(n-1, W-wt[n-1]), solve(n-1, W));
    else 
        return dp[n][W] = solve(n-1, W);
}


long long solve2(int n, int W){
    long long dp[n+1][W+1];
    for(int i = 0;i<n+1;i++)
        for(int j = 0;j<W+1;j++)
            if(i == 0 || j == 0)dp[i][j] = 0LL;

    for(int i = 1;i<n+1;i++){
        for(int j = 1 ;j<W+1;j++){
            if(wt[i-1] <= j)
                dp[i][j] = max(val[i-1] + dp[i-1][j-wt[i-1]], dp[i-1][j]);
            else 
                dp[i][j] = dp[i-1][j];
        }
    }
    return dp[n][W];
}            
int main(){
    memset(dp, -1, sizeof(dp));
    int n, W;
    cin>>n>>W;
    for(int i = 0; i < n; i++){
        cin>>wt[i]>>val[i];
    }
    long long ans = solve(n, W);
    cout<<ans<<endl;
    return 0;
}