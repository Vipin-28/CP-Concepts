#include<bits/stdc++.h>
using namespace std;
// Fermat's Little Theorem
// log(m) inverse modulo 
// a^-1 = a^(m-2)%m iff m is prime
int power(int a, int n){
    if(n == 0)return 1;
    int temp = power(a, n/2);
    if(n%2 == 0)
        return temp*temp;
    else return temp*temp*a;
}
int solve(int a , int m){
    return power(a, m-2)%m;
}
int main(){
    int a, m;
    cin>>a>>m;
    cout<<solve(a, m);
    return 0;
}