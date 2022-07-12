#include<bits/stdc++.h>
using namespace std;
int dp[3001][3001];
int solve(string s, string t, int n, int m){
    if(n == 0 || m == 0)return 0;
    if(s[n-1] == t[m-1])
        return solve(s, t, n-1, m-1) + 1;
    else return max(solve(s, t, n-1, m), solve(s, t, n, m-1));
}
string solve1(string s, string t, int n, int m){
    int dp[n+1][m+1];
    for(int i = 0;i<n+1;i++)
        for(int j = 0;j<m+1;j++)
            if(i == 0 || j == 0)dp[i][j] = 0;
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=m;j++){
            if(s[i-1] == t[j-1])
                dp[i][j] = dp[i-1][j-1] + 1;
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    string res = "";
    int i = n, j = m;
    while(i>0 and j>0){
        if(s[i-1] == t[j-1]){
            res.push_back(s[i-1]);
            i--, j--;
        }  
        else{
            if(dp[i][j-1] > dp[i-1][j])j--;
            else i--;
        }  
    }
    reverse(res.begin(), res.end());
    return res;
}
int main(){
    string s, t;
    cin>>s>>t;
    memset(dp, -1, sizeof(dp));
    string ans = solve1(s, t, s.size(), t.size());
    cout<<ans<<endl;
    return 0;
}