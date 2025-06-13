#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>

class Solution
{
private:
    bool ispossible(vector<int> &nums, int mid, int p)
    {
        int count = 0, n = nums.size();
        for (int i = 1; i < n; i++)
        {
            if (nums[i] - nums[i - 1] <= mid)
            {
                count++;
                i++;
            }
        }
        return count >= p;
    }

public:
    int minimizeMax(vector<int> &nums, int p)
    {
        sort(nums.begin(), nums.end());
        int start = 0, end = nums.back() - nums[0];
        int ans = 0;

        while (start <= end)
        {
            int mid = (start + end) / 2;
            if (ispossible(nums, mid, p))
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};
