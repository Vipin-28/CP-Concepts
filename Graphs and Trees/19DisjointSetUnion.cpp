#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+10;

int parent[N];
int size[N]; // for size compression to add small tree in big one not vice verse
// make function se nayi node banake liye
void make(int v){
    parent[v] = v;// khud ke khud ka par initialize kar do
    size[v] = 1; //#####################
}
// find function to find parent of the parameter node
int find(int v){
    if(parent[v] == v)return v;
    // jab tek parent nhi a jata recursion chalti rhe gi
    // path compression
    return parent[v] = find(parent[v]);
}
// union function se union kar do of parents 
void Union(int a, int b){
    a = find(a);b = find(b);
    if(a != b){
        if(size[a]<size[b])swap(a, b);
        parent[b] = a;
        size[a] += size[b];
    }
}
int main(){
    int n, k;
    cin>>n>>k;
    for(int i = 1;i<=n;i++)make[i];

    while(k--){
        int u, v;
        cin>>u>>v;
        Union(u,v);
    }
    int connected_ct = 0;
    for(int i = 0;i<n;i++){
        if(find[v] == v)connected_ct++;
    }
    return 0;
}