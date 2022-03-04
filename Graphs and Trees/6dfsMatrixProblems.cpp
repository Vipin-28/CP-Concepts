// 4 dirns. mei move kar sakte hai up, down, right, left
// Question 773. Flood Fill leetcode

#include<bits/stdc++.h>
using namespace std;

const int N = 1e5+10;
vector<int> g[N];
bool vis[N];
// Time Complexity O(v+e);

// iss questoin mei visited array rakh bhi liya tho farak nhi padega


void dfs(vector<vector<int>>& image, int i, int j, int initialColor, int newColor){
    int n = image.size(), m = image[0].size();
    if(i<0 or j<0)return;
    if(i>=n or j>=m)return;
    if(image[i][j] != initialColor)return;
    image[i][j] = newColor;
    
    dfs(image, i-1, j, initialColor, newColor);
    dfs(image, i+1, j, initialColor, newColor);
    dfs(image, i, j-1, initialColor, newColor);
    dfs(image, i, j+1, initialColor, newColor);
}

vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int newColor){
    int initialColor = image[sr][sc];
    if(initialColor != newColor)
        dfs(image, sr, sc, initialColor, newColor);
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