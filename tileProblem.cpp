#include<iostream>
using namespace std;
//Top Down approach
int tiles(int n,int* dp){
    if(n==0) return 0;
    if(n>0 && n<4) return 1;
    if(n==4) return 2;
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int x = tiles(n-1,dp);
    int y = tiles(n-4,dp);
    
    return dp[n] = x+y;
}
//Bottom Up approach
int tilesdp(int n){
    int dp[100] = {0};
    dp[0] = 0;
    for(int i=1;i<4;i++) dp[i]=1;
    dp[4] = 2;
    for(int i=5;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-4];
    }
    return dp[n];
}
int main(){
    int n; cin >> n;
    int dp[100] = {0};
    cout << tiles(n,dp) << endl;
    cout << tilesdp(n) << endl;
}
