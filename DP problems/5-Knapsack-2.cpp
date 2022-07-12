// constriants are different so can't go with usual way 
// N = 1e2, W = 1e9, max val = 1e3, max weight = w
// if select all items --> we will get max_val = N*val = 1e5
// N select --> wt sum less than w --> max value (prev appr.)
// N select --> sum of values = some val --> min weight

#include<bits/stdc++.h>
using namespace std;

int wt[101], val[101];
long long dp[105][100005];

long long solve(int n, int V){
    if(V == 0)return 0;
    if(n < 0)return 1e15;//value doesn't exist
    if(dp[n][V] != -1)return dp[n][V];
    //choose
    if(V >= val[n-1])
        return dp[n][V] = min(wt[n-1] + solve(n-1, V-val[n-1]), solve(n-1, V));
    // don't choose
    else return dp[n][V] = solve(n-1, V);
}
         
int main(){
    memset(dp, -1, sizeof(dp));
    int n, w;
    cin>>n>>w;
    for(int i = 0; i < n; i++){
        cin>>wt[i]>>val[i];
    }
    int max_value = 1e5;
    for(int i = max_value; i >= 0; i--){
        if(solve(n, i) <= w){
            cout<<i<<endl;
            break;
        }
    }
    return 0;
}