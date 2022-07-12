#include<bits/stdc++.h>
using namespace std;
void convert(string& a){
    for(int i = 0;i<a.size();i++){
        int n = (int)a[i];
        n &= (1<<5);
        a[i] = (char)n;
        cout<<n<<endl;
    }
}
int main(){
    string a, b;
    cin>>a>>b;
    int n = a.size();
    convert(a);
    convert(b);
    for(int i = 0;i<n;i++){
        if(a[i] == b[i] )continue;
        else if(a[i]>b[i]){
            cout<<"1"<<endl;
            return 0;
        }    
        else if(a[i] < b[i]){
            cout<<"-1"<<endl;
            return 0;
        }
    }
    cout<<"0"<<endl;
    return 0;
}