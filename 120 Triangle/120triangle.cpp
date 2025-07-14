#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minimumTotal(vector<vector<int>> &triangle)
    {
        int n = triangle.size();
        vector<vector<int>> dp = triangle;
        for (int i = n - 2; i >= 0; i--)
        {
            int k = triangle[i].size();
            for (int j = 0; j < k; j++)
            {
                dp[i][j] += min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        return dp[0][0];
    }
};