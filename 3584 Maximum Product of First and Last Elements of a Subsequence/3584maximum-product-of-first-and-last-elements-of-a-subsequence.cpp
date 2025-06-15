#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    long long maximumProduct(vector<int> &nums, int m)
    {
        int n = nums.size();
        vector<long long> suffmax(n), suffmin(n);
        suffmax[n - 1] = nums[n - 1];
        suffmin[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--)
        {
            suffmax[i] = max(suffmax[i + 1], 1LL * nums[i]);
            suffmin[i] = min(suffmin[i + 1], 1LL * nums[i]);
        }
        long long maxi = nums[0], mini = nums[0], ans = LLONG_MIN;
        for (int i = 0; i <= n - m; i++)
        {
            maxi = max(1ll * nums[i], maxi);
            mini = min(nums[i] * 1ll, mini);
            ans = max(ans, maxi * suffmax[i + m - 1]);
            ans = max(ans, mini * suffmin[i + m - 1]);
        }
        return ans;
    }
};