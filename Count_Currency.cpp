#include <bits/stdc++.h>
using namespace std;

int DiffWays(vector<int> note, int sum, int n)
{

    int dp[n + 1][sum + 1];

    for (int j = 0; j <= n; j++)
    {
        dp[j][0] = true;
    }

    for (int i = 1; i <= sum; i++)
    {
        dp[0][i] = false;
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= sum; j++)
        {

            if (note[i - 1] <= j)
            {
                dp[i][j] = dp[i][j - note[i - 1]] + dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    return dp[n][sum];
}

int main()
{
    vector<int> note({10, 20, 50, 100, 200, 500, 1000, 2000});
    int n = 8;
    int sum = 2000;

    cout << DiffWays(note, sum, n);

    return 0;
}
