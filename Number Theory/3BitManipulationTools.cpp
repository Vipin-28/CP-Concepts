//Episode number 49

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
    for(char c = 'A';c<='D';c++){
        cout<<c<<endl;
        printBinary(c);
    }
    for(char c = 'a';c<='d';c++){
        cout<<c<<endl;
        printBinary(c);
    }

    //output looks like this and diff lies on the 5th bit
    // A00001000001  B00001000010  C00001000011  D00001000100
    // a00001100001  b00001100010  c00001100011  d00001100100
    //       *             *             *             *  

    // // A ---> a conversion
    // char A = 'A' ;
    // char a = A | (1<<5);
    // cout<<a<<endl;

    // // a ---> A conversion
    // char A = a & (~(1<<5));

    // //check power of two 
    // if(n & (n-1))cout<<"not power of two"<<endl;
    // else cout<<"power of two"<<endl;

    return 0;
}