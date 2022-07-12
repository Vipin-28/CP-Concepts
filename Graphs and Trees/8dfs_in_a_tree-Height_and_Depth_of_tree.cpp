#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
// bool vis[N];  visited array in not needed in tree
int depth[N], height[N];
void dfs(int vertex, int par=0){ 
    
    for(int child : g[vertex]){
        if(par == child)continue;
        depth[child] = depth[vertex] + 1;
        dfs(child, vertex);
        height[vertex] = max(height[vertex], height[child] + 1);
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
    for(int i = 1;i<=n;i++){
        cout<<depth[i]<<" "<<height[i]<<endl;
    }
    return 0;
}

/*         1 
         / | \
        /  |  \                       1   2   3   4   5   6   7   8   9   10   11   12   13 
       2   3   13                 d | 0 | 1 | 1 | 2 | 2 | 3 | 3 | 3 | 3 |  3 |  4 |  4 |  1 |
      /    |                      h | 4 | 3 | 3 | 2 | 2 | 0 | 0 | 1 | 0 | 10 |  0 |  0 |  0 |
     5     4
    /|\   / \
   6 7 8  9  10
      /       | 
     12       11
*/     

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