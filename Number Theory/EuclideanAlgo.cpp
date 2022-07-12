#include<bits/stdc++.h>
using namespace std;
//TC-O(log(max(a, b)))
int gcd(int a, int b){
    return b == 0? a: gcd(b, a%b);
}
int main(){
    int a, b;
    cin>>a>>b;
    int ans = gcd(a, b);
    cout<<ans<<endl;
    int lcm = (a*b)/ans;
    cout<<lcm<<endl;
    return 0;
}