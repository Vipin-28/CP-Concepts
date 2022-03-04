#include "bits/stdc++.h"
using namespace std;
const int N = 10^4;
vector<int> adjList[N];
bool vis[N];
bool isCyclicUtil(vector<int> adjList[], vector<bool>& visited, vector<bool>& stack, int i){
    stack[i] = true;
    visited[i] = true;
    for(auto child : adjList[i]){
        if(!visited[child] and isCyclicUtil(adjList, visited, stack, child))return true;
        if(stack[child])return true;
    }
    stack[i] = false;
    return false;
}
bool isCyclic(vector<int> adjList[], int n){
    vector<bool> stack(n, false), visited(n, false);
    for(int i = 0;i<n;i++){
        if(!visited[i] and isCyclicUtil(adjList, visited, stack, i))return true;
    }
    return false;
}
int main(){
    int v, e;
    cin>>v>>e;
    for(int i = 0;i<e;i++){
        int x, y; cin>>x>>y;
        adjList[x].push_back(y);
    }
    bool cyclic = isCyclic(adjList, v);
    (cyclic) ? cout<<"Cycle is present" : cout<<"cycle is not present";
    return 0;
}