#include<bits/stdc++.h>
using namespace std;
int INF = 9999999;
void dfs(set<int> graph[],  int n, vector<int> temp, vector<vector<int>>& res, int src){
    temp.push_back(src);
    if(graph[src].size() == 0){
        res.push_back(temp);
        return ;
    }
    for(auto child : graph[src]){
        dfs(graph, n, temp, res, child);
    }
}

int solve(vector<int>& nums){
    int n = nums.size();
    vector<int> dp(n, INF);
    dp[0] = 0;

    for(int i = 0;i<n;i++){
        for(int j = i;j<=nums[i]+i and j<n;j++){
            dp[j] = min(dp[j], dp[i]+1);
        }
    }
    
    if(dp[n-1] == INF)return 0;

    set<int> graph[n];
    queue<int> q;
    q.push(n-1);
    while(!q.empty()){ 
        int idx = q.front();
        q.pop();
        int dist = dp[idx];
        for(int i = idx-1; i >= 0; i--){
            if(dp[i] == dist-1 and nums[i]+i >= idx){
                graph[idx].insert(i);
                q.push(i);
            }
        }
    }

    vector<vector<int>> res;
    vector<int> temp;
    dfs(graph, n, temp, res, n-1);
    
    for(int i = 0;i<res.size();i++){
        reverse(res[i].begin(),res[i].end());
        for(int j = 0;j<res[i].size();j++){
            cout<<res[i][j]<<" ";
        }
        cout<<endl;
    }
    return dp[n-1];
}
int main(){
    int n;
    cin>>n;
    vector<int> nums(n);
    for(int i = 0; i < n; i++)
        cin>>nums[i];
    cout<<solve(nums)<<endl;
    return 0;
}

// 10
// 3 3 0 2 1 2 4 2 0 0