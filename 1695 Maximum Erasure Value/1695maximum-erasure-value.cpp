#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maximumUniqueSubarray(vector<int> &nums)
    {
        int l = 0, n = nums.size(), sum = 0, ans = 0;
        ;
        unordered_map<int, int> mapp;
        for (int r = 0; r < n; r++)
        {
            if (mapp.find(nums[r]) != mapp.end())
            {
                while (l <= mapp[nums[r]])
                {
                    sum -= nums[l];
                    l++;
                }
            }
            sum += nums[r];
            ans = max(ans, sum);
            mapp[nums[r]] = r;
        }
        return ans;
    }
};