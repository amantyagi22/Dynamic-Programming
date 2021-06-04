#include<iostream>
using namespace std;
//Top down approach
int fp(int n,int* dp){
    if(n==0||n==1){
        return 1;
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ip = (n-1)*fp(n-2,dp);
    int ipn = fp(n-1,dp);
    return dp[n] = ip+ipn;
}
//Bottom Up approach
int fpdp(int n){
    int dp[100] = {0};
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[n-1] + (n-1)*dp[n-2];
    }
    return dp[n];
}
int main(){
    int n; cin >> n;
    int dp[100] = {0};
    cout << fp(n,dp) << endl;
    cout << fpdp(n) << endl;
}
