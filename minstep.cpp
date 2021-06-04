#include <bits/stdc++.h>
using namespace std;
//Top down Approach
int minstep(int n, int *dp)
{
    if (n == 1)
    {
        return 0;
    }

    if (dp[n] != 0)
    {
        return dp[n];
    }

    int x, y, z;
    x = y = z = INT_MAX;

    if (n % 3 == 0)
    {
        x = minstep(n / 3, dp);
    }
    if (n % 2 == 0)
    {
        y = minstep(n / 2, dp);
    }
    z = minstep(n - 1, dp);

    return dp[n] = min(x, min(y, z)) + 1;
}
//Bottom up Approach
int minStepDp(int n)
{
    int dp[n + 1] = {0};
    dp[1] = 0;
    for (int i = 2; i <= n; i++)
    {
        int x, y, z;
        x = y = z = INT_MAX;
        if (i % 3 == 0)
        {
            x = dp[i / 3];
        }
        if (i % 2 == 0)
        {
            y = dp[i / 2];
        }
        z = dp[i - 1];
        dp[i] = min(min(x, y), z) + 1;
    }
    return dp[n];
}
int main()
{
    int n;
    cin >> n;
    int dp[1000] = {0};
    cout << minstep(n, dp) << endl;
    cout << minStepDp(n) << endl;
}
