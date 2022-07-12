#include<bits/stdc++.h>
using namespace std;
void helper(set<string>& st, string temp){
    do{
        st.insert(temp);
    }while(next_permutation(temp.begin(), temp.end()));
}
double solve(set<string> st, vector<double>& p, int n){
    int size = st.size();
    double ans = 0.0;
    for(auto e : st){
        double temp = 1.000000000;
        for(int j = 0;j<n;j++){
            if(e[j] == 'H')
                temp *= p[j];
            else temp *= 1-p[j];
        }
        ans += temp;
    }
    return ans;
}
int main(){
    int n;
    cin>>n;
    vector<double> p(n);
    for(int i = 0; i < n; i++)
        cin>>p[i];
    set<string> combs;
    int countmn = n/2 + 1;
    for(int i = countmn;i<=n;i++){
        string temp1(i, 'H'), temp2(n-i, 'T');
        string temp = temp1 + temp2;
        helper(combs, temp);
    }
    cout<<fixed<<setprecision(10)<<solve(combs, p, n)<<endl;
    return 0;
}