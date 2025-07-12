#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
public:
    int nthSuperUglyNumber(int n, vector<int> &primes)
    {
        int k = primes.size();
        vector<int> dp(n, 1);
        vector<int> indices(k, 0);
        for (int i = 1; i < n; i++)
        {
            int temp = INT_MAX;
            for (int j = 0; j < k; j++)
            {
                temp = min(temp * 1l,  1l* dp[indices[j]] * primes[j]);
            }
            dp[i] = temp;
            for (int j = 0; j < k; j++)
            {
                if (1l*dp[indices[j]] * primes[j] == temp)
                {
                    indices[j]++;
                }
            }
        }
        return dp[n - 1];
    }
};