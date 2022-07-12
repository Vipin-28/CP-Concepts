#include<bits/stdc++.h>
using namespace std;
void primeFactors(int n){
    vector<int> factors;
    if(n%2 == 0)factors.push_back(2);
    for(int i = 3;i<=sqrt(n);i+=2){
        while(n%i == 0){
            factors.push_back(i);
            n = n/i;
        }    
    }
    //!!!!!!!!!!Important!!!!!!!!!!!//
    if(n>2)factors.push_back(n);
    for(auto e: factors)cout<<e<<" ";
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    primeFactors(n);
    return 0;
}