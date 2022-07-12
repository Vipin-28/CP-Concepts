//Episode number 11

// Given a number N. Print its factorial
// constraints
// 1<=N<=100


// print answer module M
// where M = 47
// M = 10^9 + 7;

#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int M = 47;
    long long fact = 1;
    for(int i = 2;i<=n;i++){
        fact = (fact*i)%M;
    }
    //20 tek thik chalega
    //21 pe overflow ho jayega and ans will be a negative no.
    cout<<fact;
    return 0;
}