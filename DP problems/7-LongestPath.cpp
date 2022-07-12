#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
vector<int> graph[N];
int dp2[N];
void reset(int n, vector<int>& vis){
    for(int i = 0;i<n;i++){
        vis[i] = false;
    }    
}
void dfs(int src, vector<int>& vis, int dp2[], int dist){
    if(vis[src-1])return;
    vis[src-1] = true;
    dp2[src-1] = max(dist, dp2[src-1]);
    int firstChild = 1;
    for(auto child : graph[src]){
        if(firstChild){
            dist += 1;
            firstChild = false;
        }    
        dfs(child, vis,  dp2, dist);
        vis[child-1] = false;
    }
}
int solve(int n){
    int ans = INT_MIN;
    vector<int> vis(n, false);
    for(int i = 1;i<=n;i++){
        reset(n, vis);
        dfs(i, vis, dp2, 0);
    }
    for(int i = 0;i<n;i++)
        ans = max(ans, dp2[i]);
    return ans;
}
int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int u,v;
        cin>>u>>v;
        graph[u].push_back(v);
    }
    int ans = solve(n, m);
    cout<<ans<<endl;
}