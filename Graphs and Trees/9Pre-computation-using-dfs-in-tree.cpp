// DFS SubTree Questions 
// -Precomputation using DFS
// -subTree sum queries 
// -Even odd counts in subTree

#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

/* Given Q queries  = 10^5
   In each query given V,
   Print subtree sum of V & Number of even numbers 
   in subTree of V 
*/   

vector<int> g[N];
int subtree_sum[N]; // for precomputation of sum of subtree
int val[N]; // herr ek node ki a ek value given hai

int even_ct[N];

int depth[N], height[N];
void dfs(int vertex, int par=0){ 
    
    subtree_sum[vertex] += val[vertex];  // jate time likho yeha aate time doesn't matter
    if(vertex % 2 == 0)even_ct[vertex]++;
    for(int child : g[vertex]){
        if(child == par)continue;
        dfs(child, vertex);
        subtree_sum[vertex] += subtree_sum[child];

        even_ct[vertex] += even_ct[child];
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
    //dfs(1);
    int q;

    //this will not work as q = 10^5 and N^2 ho jayega T.C.
    // so do some precomputation
    // while(q--){
    //     int v;
    //     cin>>v;
    //     dfs(v);   // for the sum of subtrees
    //     dfs2(v);  // for the even nodes
    // }

    dfs(1); // karna padega taki precompute ho jaye pehle se
    while(q--){
        int v;
        cin>>v;
        cout<<subtree_sum[v]<<" "<<even_ct[v]<<endl;
    }
    return 0;
}