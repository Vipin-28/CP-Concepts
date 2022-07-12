#include<bits/stdc++.h>
using namespace std;
const int M = 1e9+7;
int n, m;
void dfs(vector<vector<char>>& grid, vector<vector<bool>>& vis, int i, int j, int&count){
    if(i<0 || j<0 || i>=n || j>=m)return ;
    if(grid[i][j] == '#')return ;
    //cout<<i<<" "<<j<<" "<<count<<endl;
    if(i == n-1 and j == m-1){
        count = (count+1)%M;
        return ;
    }
    if(vis[i][j])return ;
    vis[i][j] = true;    
    dfs(grid, vis, i+1, j, count);
    dfs(grid, vis, i, j+1, count);
    vis[i][j] = false;
}
int solve(vector<vector<char>>& grid){
    vector<vector<bool>> vis(n, vector<bool>(m, false));
    int count = 0;
    dfs(grid, vis, 0, 0, count);
    return count;
}
int solve2(vector<vector<char>>& grid){
    int dp[n][m];
    int firsttime = false;
    for(int i = 0;i<n;i++){
        if(grid[i][0] == '#'){
            dp[i][0] = 0;
            firsttime = true;
        }
        else{
            if(firsttime)dp[i][0] = 0;
            else dp[i][0] = 1;
        }
    }    

    firsttime = false;
    for(int i = 0;i<m;i++){
        if(grid[0][i] == '#'){
            dp[0][i] = 0;
            firsttime = true;
        }
        else{
            if(firsttime)dp[0][i] = 0;
            else dp[0][i] = 1;
        }
    }
    for(int i = 0;i<n;i++)
        for(int j= 0;j<m;j++)
            if(grid[i][j] == '#')dp[i][j] = 0;

    for(int i = 1;i<n;i++){
        for(int j= 1;j<m;j++){
            if(grid[i][j] == '#')continue;
            dp[i][j] = (dp[i-1][j] + dp[i][j-1])%M;
        }
    }
    return dp[n-1][m-1];
}
int main(){
    // int n, m;
    cin>>n>>m;
    vector<vector<char>> grid(n, vector<char>(m));
    for(int i = 0; i < n; i++)
        for(int j = 0; j < m; j++)
            cin>>grid[i][j];
    int ans = solve2(grid);
    cout<<ans<<endl;
    return 0;
}