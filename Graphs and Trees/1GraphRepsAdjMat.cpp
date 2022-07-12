#include<bits/stdc++.h>
using namespace std;
const int N = 1e3+10;
int graph[N][N]; // global declared variable is initialised with 0 value.
// O(N^2) - space complexity
// agar N ki value boht jyada hui jaise 10^6 then we can't do this by adj mat
// 10^7 - 10^8 se bade arrays nhi bana sakte
int main(){
    int n, m;  //n = vertices, m = edges
    cin>>n>>m;
    for(int i = 0;i<m;i++){
        int v1, v2, wt;
        cin>>v1>>v2;
        graph[v1][v2] = 1;
        graph[v2][v1] = 1;

        // in case of weighted graph
        // graph[v1][v2] = wt;
        // graph[v2][v1] = wt;

    }

    return 0;
}