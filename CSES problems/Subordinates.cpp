#include<bits/stdc++.h>
using namespace std;
const int N = 2*1e5;
vector<int> graph[N];
unordered_map<int, set<int>> g;

int main(){
    int n;
    cin>>n;
    for(int i = 2;i<=n;i++){
        int x;
        cin>>x;
        graph[1].push_back(i);
        graph[x].push_back(i);
        g[1].insert(i);
        g[x].insert(i);
    }
    vector<int> res;
    for(int i = 1;i<=n;i++){
        // cout<<i<<"->";
        // for(auto e: graph[i]){
        //     cout<<e<<"->";
        // }
        // cout<<endl;
        // res.push_back(graph[i].size());
        res.push_back(g[i].size());
    }
    for(auto ele : res){
        cout<<ele<<" ";
    }
    cout<<endl;
    return 0;
}