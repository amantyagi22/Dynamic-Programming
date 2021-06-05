#include<iostream>
using namespace std;
//Top Down approach
int coinchange(int* arr,int n,int m,int dp[][100]){
    if(m<0) return 0;
    
    //Do not include any coin
    if(m==0) return 1;
    
    //No coins left but amount is >0
    if(n<=0 && m>0) return 0;
    
    if(dp[n][m]!=0){
        return dp[n][m];
    }
    
    //take the nth term 
    int op1 = coinchange(arr,n-1,m,dp);
    //do not take the nth term
    int op2 = coinchange(arr,n,m-arr[n-1],dp);
    
    return dp[n][m] = op1 + op2;
}

//Bottom up approach
int coinchangedp(int* arr,int n,int m){
    int dp[100][100];
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i==0){
                dp[i][j] = 0;
            }else if(j==0){
                dp[i][j] = 1;
            }else if(arr[i-1]>j){
                /*in this we do not include the coin
                as we can't make j 
                from a bigger coin than j*/
                dp[i][j] = dp[i-1][j];
            }else{
                dp[i][j] = dp[i-1][j] + dp[i][j-arr[i-1]];
            }
        }
    }
    return dp[n][m];
}

int main(){
    int size; cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }
    int bcoin; cin >> bcoin;
    int dp[100][100] = {0};
    cout << coinchange(arr,size,bcoin,dp) << endl;
    cout << coinchangedp(arr,size,bcoin) << endl;
}
