#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int findLength(vector<int> &nums1, vector<int> &nums2)
    {
        int s1 = nums1.size(), s2 = nums2.size();
        int ans = 0;
        vector<vector<int>> dp(s1 + 1, vector<int>(s2 + 1));
        for (int i = 1; i <= s1; i++)
        {
            for (int j = 1; j <= s2; j++)
            {
                if (nums1[i - 1] == nums2[j - 1])
                {
                    dp[i][j] = max(dp[i][j], dp[i - 1][j - 1] + 1);
                }
                ans = max(ans, dp[i][j]);
            }
        }
        return ans;
    }
};