#include<bits/stdc++.h>
using namespace std;

// Here Space complexity is O(v+e)
// N != 10^5 (will not be possible)
// agar N vertices hai tho max edges N^2 ho sakte hai
const int N = 1e3+10;
vector<int> graph2[N];

// for weighted adjacency list
// vector<pair<int,int>> graph2[N];

int main(){
    int n, m;
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int v1, v2, wt;
        cin>>v1>>v2>>wt;

        graph2[v1].push_back(v2);
        graph2[v2].push_back(v1);

        // graph2[v1].push_back({v2, wt});
        // graph2[v2].push_back({v1, wt});
    }
    return 0;
}