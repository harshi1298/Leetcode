#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int maxSubarraySumCircular(vector<int> &nums)
    {
        int n = nums.size();
        vector<int> pre(n), suff(n);
        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        int sum = nums[0], maxsum = INT_MIN;
        for (int i = 1; i < n; i++)
        {
            sum += nums[i];
            pre[i] = max(pre[i - 1], sum);
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum = max(sum, nums[i]);
            maxsum = max(maxsum, sum);
        }
        sum = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            sum += nums[i];
            suff[i] = max(suff[i + 1], sum);
        }
        for (int i = 0; i < n - 1; i++)
        {
            maxsum = max({maxsum, pre[i] + suff[i + 1]});
        }
        return maxsum;
    }
};