#include<iostream>
using namespace std;

//Top down approach
int tiles(int n,int m,int* dp){
    if(n==0) return 0;
    if(n>0 && n<m) return 1;
    if(n==m) return 2;
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int x = tiles(n-1,m,dp);
    int y = tiles(n-m,m,dp);
    
    return dp[n] = x+y;
}
//Bottom Up approach
int tilesdp(int n,int m){
    int dp[100] = {0};
    for(int i=0;i<=n;i++){
        if(i==0) dp[i] = 0;
        else if(i>0 && i<m) dp[i] = 1;
        else if(i==m) dp[i] = 2;
        else dp[i] = dp[i-1] + dp[i-m];
    }
    return dp[n];
}
int main(){
    int n,m; cin >> n >> m;
    int dp[100] = {0};
    cout << tiles(n,m,dp) << endl;
    cout << tilesdp(n,m) << endl;   
}
//The block given is nxm and tile is 1xm or mx1
