#include<iostream>
using namespace std;
//Top Down approach
int ladder(int n,int k,int* dp){
    if(n==0) return 1;
    if(dp[n]!=0){
        return dp[n];
    }
    int ans = 0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            ans += ladder(n-i,k,dp);
        }
    }
    return dp[n] = ans;
}
//Bottom Up approach Time comp. : O(n*k)
int ladderdp(int N,int k){
    int dp[100] = {0};
    dp[0] = dp[1] = 1;
    for(int n=2;n<=N;n++){
        dp[n] = 0;
        for(int i=1;i<=k;i++){
            if(n-i>=0){
                dp[n] += dp[n-i];
            }
        }
    }
    return dp[N];
}
//Optimized apporach Time comp. : O(k)
int ladder_optimised(int n,int k){
    int dp[100] = {0};
    
    dp[0] = dp[1] = 1;
    // for the values n<=k
    for(int i=2;i<=k;i++){
        dp[i] = 2*dp[i-1];
    }
    //for the values n>k
    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1] - dp[i-k-1];
    }
    return dp[n];
}
int main(){
    int n,k; cin >> n >> k;
    int dp[100] = {0};
    cout << ladder(n,k,dp) << endl;
    cout << ladderdp(n,k) << endl;
    cout << ladder_optimised(n,k) << endl;
}
