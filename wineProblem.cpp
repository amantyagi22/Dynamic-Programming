#include<iostream>
using namespace std;

//Top Down approach
int winePrice(int i,int j,int* arr,int y,int dp[][1000]){
    if(i>j){
        return 0;
    }
    if(dp[i][j]!=0){
        return dp[i][j];
    }
    
    int op1 = arr[i]*y + winePrice(i+1,j,arr,y+1,dp);
    int op2 = arr[j]*y + winePrice(i,j-1,arr,y+1,dp);
    
    return dp[i][j]=max(op1,op2);
}

//Bottom Up approach
int profit(int* arr,int size){
    
    int dp[100][100] = {0};
    for(int i=0;i<size;i++){
        for(int j=0;j<size;j++){
            if(i==j){
                dp[i][j] = arr[i]*size;
            }
        }
    }
    /*
    for(int i=0,j=1;i<size&&j<size;i++,j++){
            if(i<j){
                int y = size - (j-i);
                int op1 = arr[i]*y + dp[i+1][j];
                int op2 = arr[j]*y + dp[i][j-1];
                dp[i][j]=max(op1,op2);
                cout << dp[i][j] << "i: "<<i<<" ,j: "<< j << endl;
            }
    }
    */
    int i=0,j=1;
    while(j<size){
            int I = i;
            int J = j;
        while(I<size && J<size){
            int y = size - (J-I);
            int op1 = arr[I]*y + dp[I+1][J];
            int op2 = arr[J]*y + dp[I][J-1];
            dp[I][J]=max(op1,op2);
            I++;
            J++;
        }
        j++;
    }
    return dp[0][size-1];
}
int main(){
    int size; cin >> size;
    int arr[size];
    for(int i=0;i<size;i++){
        cin >> arr[i];
    }    
    int dp[1000][1000]={0};
    cout << winePrice(0,size-1,arr,1,dp) << endl;
    cout << profit(arr,size) << endl;
}
