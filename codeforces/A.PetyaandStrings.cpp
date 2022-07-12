#include<bits/stdc++.h>
using namespace std;
int main(){
    string a, b;
    cin>>a>>b;
    int n = a.size();
    for(int i = 0;i<n;i++){
        if(a[i] == b[i] || abs(a[i] - b[i]) == 32)continue;
        else if(a[i]>b[i]){
            cout<<"-1"<<endl;
            return 0;
        }    
        else{
            cout<<"1"<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl;
    return 0;
}