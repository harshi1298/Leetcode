#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int lengthOfLIS(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> temp;
        for (int i = 0; i < n; i++)
        {
            if (temp.empty() || temp.back() < nums[i])
            {
                temp.push_back(nums[i]);
            }
            else
            {
                int t = lower_bound(temp.begin(), temp.end(), nums[i]) - temp.begin();
                temp[t] = nums[i];
            }
        }
        return temp.size();
    }
};