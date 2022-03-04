//Episode number 47 and 48


#include<bits/stdc++.h>
using namespace std;
void printBinary(int n){
    int i = 0;
    for(int i = 10;i>=0;i--){
        cout<<((n>>i)&1);
    }
    cout<<endl;
}
int main(){
    int n;
    cin>>n;
    printBinary(n);

    // //set ith bit (use or)
    // printBinary(n | (1<<i));

    // //unset ith bit (use and)
    // printBinary(n &(~(1<<i))) ;

    // //toggle ith bit (use XOR)
    // printBinary(n ^ (1<<i));

    // //count number of set bits 
    // int count = 0;
    // for(int i = 31; i>=0 ;i--){
    //     if((n & (1<<i)) != 0)count++;
    // }
    // cout<<count<<endl;

    // builtin function for number of set bits 
    // int count = __builtin_popcount(n);


    return 0;
}