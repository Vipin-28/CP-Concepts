#include<bits/stdc++.h>
using namespace std;
int solve(int a, int m){
    for(int x = 1;x<m;x++)
        if(((a%m) * (x%m))%m == 1)return x;
}
int main(){
    int a, m;
    cin>>a>>m;
    // I have to find (1/a)%m 
    cout<<solve(a, m);
    return 0;
}