#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minTaps(int n, vector<int> &ranges)
    {
        vector<int> temp(n+1);
        for (int i = 0; i <= n; ++i)
        {
            int left = max(0, i - ranges[i]);
            int right = min(n, i + ranges[i]);
            temp[left] = max(temp[left], right);
        }
        vector<int> dp(n + 1, INT_MAX);
        dp[n] = 0;
        for (int i = n - 1; i >= 0; --i)
        {
            if (temp[i] == 0)
                continue;
            for (int j = i + 1; j <= temp[i]; ++j)
            {
                if (dp[j] != INT_MAX)
                {
                    dp[i] = min(dp[i], dp[j] + 1);
                }
            }
        }
        return dp[0] == INT_MAX ? -1 : dp[0];
    }
};