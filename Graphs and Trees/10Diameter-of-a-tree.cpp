#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

vector<int> g[N];
int depth[N];
void dfs(int vertex, int par=0){ 
   
    for(int child : g[vertex]){
        if(child == par)continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        
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
    dfs(1);
    int mx_depth = -1;
    int mx_d_node;
    for(int i = 1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
            mx_d_node = i;
        }
        depth[i] = 0;
    }
    dfs(mx_d_node);
    mx_depth = -1;
    for(int i = 1;i<=n;i++){
        if(mx_depth < depth[i]){
            mx_depth = depth[i];
        }
    }
    cout<<mx_depth<<endl;
    return 0;
}

// 13
// 1 2
// 1 3
// 1 13
// 2 5
// 3 4
// 5 6
// 5 7
// 5 8
// 8 12
// 4 9
// 4 10
// 10 11