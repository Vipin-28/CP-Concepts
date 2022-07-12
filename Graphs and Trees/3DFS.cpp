#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
// Time Complexity O(v+e);
void dfs(int vertex){
    // section1
    // Take action on vertex after entering the vertex
    if(vis[vertex])return ;
    vis[vertex] = true;
    for(int child : g[vertex]){
        // section2
        // Take action on child befroe entering child node
        if(vis[child])continue;
        dfs(child);
        // section3
        // Take action on child after exiting child node
    }
    // section4
    // Take actoin on vertex before extiting the vertex
}

int main(){
    int n,m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int v1, v2;
        cin>>v1>>v2;
        g[v1].push_back(v2);
        g[v2].push_back(v1);
    }
    return 0;
}