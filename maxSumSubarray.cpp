#include<iostream>
using namespace std;
/*
Space optimized solution
|| Kadane's algorithm ||
This will handle all special cases
including all negative elements
*/
int kadane(int* arr,int n){
    int current_sum, max_sum;
    current_sum = max_sum = arr[0];
    
    for(int i=1;i<n;i++){
        if(current_sum >= 0){
            current_sum+=arr[i];
        }else{
            current_sum = arr[i];
        }
        max_sum = max(max_sum,current_sum);
    }
    
    return max_sum;
}
//Top down approach
//Kadane in recursion+memoization
int maxSum(int* arr,int n,int s,int* dp){
    if(s==0){
        return dp[s] = arr[s];
    }
    if(dp[s]!=0){
        return dp[s];
    }
    int smallOutput = maxSum(arr,n,s-1,dp);
    int cntu = smallOutput + arr[s];
    //Check for previous sum to know
    //Wheter to continue or start a new one
    int ans = (smallOutput>=0?cntu:arr[s]);
    return dp[s] = ans;
}
//Bottom Up approach
//Kadane in dp
int maxSumdp(int* arr,int n){
    int max_so_far, dp[1000] = {0};
    max_so_far = dp[0] = arr[0];
    
    for(int i=1;i<n;i++){
        if(dp[i-1] >= 0){
            dp[i]=dp[i-1]+arr[i];
        }else{
            dp[i] = arr[i];
        }
        max_so_far = max(max_so_far,dp[i]);
    }
    return max_so_far;
}

int main(){
    int n; cin >> n;
    int arr[n];
    for(int i=0;i<n;i++) cin >> arr[i];
    int dp[100] = {0};
    cout << maxSum(arr,n,n-1,dp) << endl;
    cout << maxSumdp(arr,n) << endl;
    cout << kadane(arr,n) << endl;
}
