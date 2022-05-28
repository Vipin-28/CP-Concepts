#include<bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>& grid){
    int n = grid.size(), m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, 0));
    for(int i = 0;i<n;i++)dp[i][0] = grid[i][0];
    for(int i = 0;i<m;i++)dp[0][i] = grid[0][i];

    for(int i = 1;i<n;i++){
        for(int j = 1;j<m;j++){
            dp[i][j] = min({dp[i][j-1], dp[i-1][j], dp[i-1][j-1]})+1;
        }
    }
    int mx = INT_MIN;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cout<<dp[i][j]<<" ";
            mx = max(mx, dp[i][j]);
        }    
        cout<<endl;
    }    
    return mx;
}   
int main(){
    int n, m;
    cin>>n>>m;
    vector<vector<int>> grid(n, vector<int>(m));
    for(int i = 0;i<n;i++)
        for(int j = 0;j<m;j++)
            cin>>grid[i][j];
    
    cout<<solve(grid);
    return 0;
}