#include<iostream>
using namespace std;
/*I can comefrom n/2 --> n by doubling it 
So the double state is we are calling is to half
and for increasing state we will call on decreasing state
so that we can come up to the required state by increasing it
Basically revesre engg. */

// Top Down approach
int cellProblem(int n,int x,int y,int z,int* dp){
    if(n==0 || n==1) return 0;
    
    if(dp[n]!=0){
        return dp[n];
    }
    
    if(n%2==0){
        int inc = cellProblem(n-1,x,y,z,dp) + y;
        int dbl = cellProblem(n/2,x,y,z,dp) + x;
        return dp[n] = min(inc,dbl);
    }else{
        int inc = cellProblem(n-1,x,y,z,dp) + y;
        int dec_dbl = cellProblem((n+1)/2,x,y,z,dp) + z + x;
        return dp[n] = min(inc,dec_dbl);
    }
}

//Bottom Up approach
int cellProblemdp(int n,int x,int y,int z){
    int dp[100] = {0};
    dp[0] = dp[1] = 0;
    for(int i=2;i<=n;i++){
        if(i%2==0){
            dp[i] = min(dp[i/2] + x,dp[i-1] + y);
        }else{
            dp[i] = min(dp[(i+1)/2]+z+x,dp[i-1]+y);
        }
    }
    return dp[n];
}

int main(){
    int n,x,y,z;
    cin >> n >> x >> y >> z;
    int dp[100] = {0};
    cout << cellProblem(n,x,y,z,dp) << endl;
    cout << cellProblemdp(n,x,y,z) << endl;
}
