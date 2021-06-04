#include<iostream>
#include<climits>
using namespace std;
//Top Down approach
int minCoinChange(int n,int* coins,int m,int* dp){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ans = INT_MAX;
    for(int i=0;i<m;i++){
        if(n - coins[i] >=0){
            ans = min(ans,minCoinChange(n-coins[i],coins,m,dp));
        }
    }
    return dp[n]=ans+1;
}
//Bottom Up approach
int minCoinChangedp(int n,int* coins,int m){
    int dp[1000] = {0};
    
    for(int i=1;i<=n;i++){
        int ans = INT_MAX;
        for(int j=0;j<m;j++){
            if(i - coins[j] >=0){
                ans = min(ans,dp[i-coins[j]]);
            }   
        }
        dp[i] = ans + 1;
    }
    
    return dp[n];
}
int main(){
    int n; cin >> n;
    int m; cin >> m;
    int coins[m],dp[1000] = {0};
    for(int i=0;i<m;i++) cin >> coins[i];
    cout << minCoinChange(n,coins,m,dp) << endl;
    cout << minCoinChangedp(n,coins,m) << endl;
}
