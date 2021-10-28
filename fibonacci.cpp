#include<iostream>
using namespace std;



//Top down approach
int fib(int n,int* dp){
    if(n==0 || n==1){
        dp[n] = n;
        return n; 
    }
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    int ans = fib(n-1,dp) + fib(n-2,dp);
    return dp[n] = ans;    
}
//Bottom Up approach
int fibBU(int n){
    int dp[100] = {0};
    dp[1] = 1;
    for(int i=2;i<=n;i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}
//Bottom Up approach with Space optimization
int fibSpaceOp(int n){
    if(n == 0 || n == 1){
        return n;
    }
    int a = 0, b = 1,c;
    for(int i=2;i<=n;i++){
        c = a + b;
        a = b;
        b = c;
    }
    return c;
}

int main(){
	int n; cin >> n;
	int dp[100] = {0};
	cout << fibSpaceOp(n) << endl;
}
