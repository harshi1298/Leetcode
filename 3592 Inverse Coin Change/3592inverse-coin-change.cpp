#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>

class Solution
{
public:
    vector<int> findCoins(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        vector<int> present(n, 0);

        for (int i = 0; i < n; i++)
        {
            int amount = i + 1;
            if (nums[amount - 1] > dp[amount])
            {
                present[i] = 1;
                for (int j = amount; j <= n; j++)
                {
                    dp[j] += dp[j - amount];
                }
            }
        }
        for (int i = 1; i <= n; i++)
        {
            if (dp[i] != nums[i - 1])
                return {};
        }
        vector<int> ans;
        for (int i = 0; i < n; i++)
        {
            if (present[i])
                ans.push_back(i + 1);
        }

        return ans;
    }
};
