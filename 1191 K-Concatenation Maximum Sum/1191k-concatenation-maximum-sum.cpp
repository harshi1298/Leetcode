#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int mod = 1e9 + 7;
    int kConcatenationMaxSum(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<int> pre(n), suff(n);
        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];
        int sum = (nums[0]), maxsum = 0;
        for (int i = 1; i < n; i++)
        {
            sum += nums[i];
            pre[i] = max({pre[i - 1], sum, 0});
        }
        sum = 0;
        for (int i = 0; i < n; i++)
        {
            sum += nums[i];
            sum = max(sum, 0);
            maxsum = max(maxsum, sum);
        }
        sum = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            sum += nums[i];
            suff[i] = max({suff[i + 1], sum, 0});
        }
        int rosum = 0;
        for (int i = 0; i < n - 1; i++)
        {
            rosum = max({rosum, pre[i] + suff[i + 1]});
        }
        int total = accumulate(nums.begin(), nums.end(), 0);
        if(k==1)return maxsum;
         long long result = max({maxsum*1l, rosum*1l, total > 0 ? 1l*pre[n - 1] + 1l*(k - 2) * total + suff[0]*1l : 0L});
        return result % mod;
    }
};