#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numSquares(int n)
    {
        int st = sqrt(n) + 1;
        vector<vector<int>> dp(st + 1, vector<int>(n + 1, INT_MAX));
        for (int i = 0; i < st + 1; i++)
        {
            dp[i][0] = 0;
        }
        for (int i = 1; i <= st; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                dp[i][j] = min(dp[i - 1][j], dp[i][j]);
                if (j - (i * i) >= 0)
                {
                    dp[i][j] = min(dp[i][j], dp[i][j - (i * i)]+1);
                }
            }
        }
        return dp[st][n];
    }
};