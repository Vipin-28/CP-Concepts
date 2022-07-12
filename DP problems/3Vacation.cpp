#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int dp[N][3];
void solve(vector<vector<int>>& grid, int n){
    dp[0][0] = grid[0][0];
    dp[0][1] = grid[0][1];
    dp[0][2] = grid[0][2];
    for(int i = 1;i<n;i++){
        dp[i][0]=max(dp[i-1][1],dp[i-1][2])+grid[i][0];
        dp[i][1]=max(dp[i-1][0],dp[i-1][2])+grid[i][1];   
        dp[i][2]=max(dp[i-1][0],dp[i-1][1])+grid[i][2];
    }
}
int main(){
    int n;
    cin>>n;
    vector<vector<int>> grid;
    for(int i = 0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        vector<int> temp = {a, b, c};
        grid.push_back(temp);
    }
    solve(grid, n);
    int ans = max({dp[n-1][0], dp[n-1][1], dp[n-1][2]});
    cout<<ans<<endl;
    return 0;
}