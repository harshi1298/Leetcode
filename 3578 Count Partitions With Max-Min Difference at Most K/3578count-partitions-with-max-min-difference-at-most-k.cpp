#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>

class Solution
{
private:
    long long mod = 1e9 + 7;

public:
    int countPartitions(vector<int> &nums, int k)
    {
        int n = nums.size();
        vector<long long> dp(n + 1, 0);  
        dp[0] = 1;
        long long prefixSum = 1; 
        int l = 0;
        priority_queue<pr> maxpq;
        priority_queue<pr, vector<pr>, greater<pr>> minpq;

        for (int i = 1; i <= n; ++i)
        {
            int val = nums[i - 1];
            maxpq.push({val, i - 1});
            minpq.push({val, i - 1});
            while (true)
            {
                while (!maxpq.empty() && maxpq.top().second < l)
                    maxpq.pop();
                while (!minpq.empty() && minpq.top().second < l)
                    minpq.pop();

                if (!maxpq.empty() && !minpq.empty() &&
                    maxpq.top().first - minpq.top().first > k)
                {
                    prefixSum = (prefixSum - dp[l] + mod) % mod;
                    l++;
                }
                else break;
            }
            dp[i] = prefixSum;
            prefixSum = (prefixSum + dp[i]) % mod;
        }

        return dp[n];
    }
};
