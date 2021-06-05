#include<iostream>
using namespace std;
/* 0 --> true, 1 --> false */

//Top Down approach
int pldString(string s,int l,int r,int dp[][100]){
    if(l>r){
        return 0;
    }
    int ans;
    if(dp[l][r]!=0){
        return dp[l][r];
    }
    if(s[l]!=s[r]){
        ans = 1;
    }else{
        ans =  pldString(s,l+1,r-1,dp);
    }
    return dp[l][r] = ans;
}

//Bottom Up Approach
int pldStringdp(string s,int l,int r){
    int dp[100][100] = {0};
    for(int i=0;i<=l;i++){
        for(int j=0;j<=r;j++){
            if(s[i]==s[j]){
                dp[i][j] = dp[i+1][j-1];
            }else{
                dp[i][j] = 1;
            }
        }
    }
    return dp[l][r];
}
//Space optimized solution
//Kadane's algorithm
int main(){
    int n; cin >> n;
    string s; cin >> s;
    int q; cin >> q;
    while(q--){
        int l,r; cin >> l >> r;
        int dp[100][100] = {0};
        if(!pldString(s,l-1,r-1,dp)){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
        if(!pldStringdp(s,l-1,r-1)){
            cout << "YES" << endl;
        }else cout << "NO" << endl;
    }
}
