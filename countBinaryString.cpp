#include<iostream>
using namespace std;

//Top down approach
int countString(int n, int last_digit, int dp[][2]) {
	if (n == 0) return 0;
	if (n == 1) {
		if (last_digit) return 1;
		else return 2;
	}

	if (dp[n][last_digit] != 0) {
		return dp[n][0];
	}

	if (last_digit == 0) {
		return dp[n][last_digit] = countString(n - 1, 0, dp) + countString(n - 1, 1, dp);
	} else {
		return dp[n][last_digit] = countString(n - 1, 0, dp);
	}
}

//Bottom Up approach
int countStringdp(int n) {
	int dp[n + 1][2] = {0};
	//if given n is 0
	dp[0][0] = dp[0][1] = 0;
	//if given n is 1 and last digit = 0
	dp[1][0] = 2;
	//if given n is 1 and last digit = 1
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		//if last digit is 0 append 0 and 1 at last
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		//if last digit is 1 append only 0 to avoid 11
		dp[i][1] = dp[i - 1][0];
	}
	return dp[n][0];
}
/* Fibonnaci approach
n = 1 --> 2 (0,1)
n = 2 --> 3 (00,10,01)
n = 3 --> 5 (000,100,010,001,101)
n = 4 --> 8 so on...
This dipicts fibonnaci starting from 2,
usually it starts from 0 as
0 1 1 2 3 5 8 ...
*/
int fib(int n) {
	if (n == 0) return 1;
	if (n == 1) return 2;

	return fib(n - 1) + fib(n - 2);
}
int main() {

	int n; cin >> n;
	int dp[100][2] = {0};
	cout << countString(n, 0, dp) << endl;
	cout << countStringdp(n) << endl;
	cout << fib(n) << endl;

	return 0;
}
