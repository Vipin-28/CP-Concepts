#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int par[N];  //it will store the parent of all the nodes 
// parent array se we can find the lca
void dfs(int vertex, int p=-1){ 
    par[vertex] = p;
    for(int child : g[vertex]){
        if(child == p)continue;
        dfs(child, vertex);
        
    }
}

vector<int> path(int v){
    vector<int> ans;
    while(v != -1){
        ans.push_back(v);
        v = par[v];
    }
    reverse(ans.begin(), ans.end());
    return ans;
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
    
    dfs(1);  // par array fill karne ke liye
    int x, y;
    cin>>x>>y;
    vector<int> path_x = path(x);
    vector<int> path_y = path(y);
    int mn_ln = min(path_x.size(), path_y.size());

    int lca = -1;
    for(int i = 0;i<mn_ln;i++){
        if(path_x[i] == path_y[i]){
            lca = path_x[i];
        }
        else{
            break;
        }
    }
    cout<<lca<<endl;
    return 0;
}