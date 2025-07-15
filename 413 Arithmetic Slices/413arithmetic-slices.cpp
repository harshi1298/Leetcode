#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numberOfArithmeticSlices(vector<int> &nums)
    {
        int n = nums.size();
        if (n < 3)
            return 0;
        int ans = 0, len = 2;
        int diff = nums[1] - nums[0];
        for (int i = 2; i < n; i++)
        {
            int diff2 = nums[i] - nums[i - 1];
            if (diff == diff2)
            {
                len++;
            }
            else
            {
                len = 2;
                diff = diff2;
            }
            if (len > 2)
            {
                ans += (len - 2);
            }
        }
        return ans;
    }
};