// InterviewBit DeleteEdge (Graph Section)

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int subtree_sum[N];
int val[N];
const int mod = 1e9+7;

void dfs(int vertex, int p=-1){ 
    
    subtree_sum[vertex] += val[vertex]; // val given hai herr ek node ki
    for(int child : g[vertex]){
        if(child == p)continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];
    }
}


int main(){
    int n;
    cin>>n;
    for(int i = 0;i<n-1;i++){
        int x, y;
        cin>>x>>y;
        g[x].push_back(y);
        g[y].push_back(x);
    }
    dfs(1); // precompute karne ke liye sum array fill ho jayega
    long long ans = 0;
    for(int i = 2;i<=n;i++){
        int part1 = subtree_sum[i];
        int part2 = subtree_sum[1]-part1; // total tree ka sum - part1 subtree sum
        ans = max(ans, (part1 * 1LL * part2)%mod);
    }
    
    return 0;
}