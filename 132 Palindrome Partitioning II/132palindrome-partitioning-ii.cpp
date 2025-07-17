#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minCut(string s)
    {
        int n = s.length();
        vector<vector<bool>> ispal(n, vector<bool>(n, 0));
        for (int i = 0; i < n; i++)
            ispal[i][i] = 1;
        for (int i = 0; i < n - 1; i++)
            ispal[i][i + 1] = (s[i] == s[i + 1]);
        for (int diff = 2; diff < n; diff++)
        {
            for (int i = 0; i < n - diff; i++)
            {
                int j = i + diff;
                ispal[i][j] = (s[i] == s[j] && ispal[i + 1][j - 1]);
            }
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[0] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j < i; j++)
            {
                if (ispal[j][i - 1])
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[n]-1;
    }
};