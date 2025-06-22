#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>

class Solution
{
public:
    int primeSubarray(vector<int> &nums, int k)
    {
        int n = nums.size();
        int maxi = *max_element(nums.begin(), nums.end());

        vector<bool> isprime(maxi + 1, true);
        isprime[0] = isprime[1] = false;
        for (int i = 2; i * i <= maxi; i++)
        {
            if (isprime[i])
                for (int j = i * i; j <= maxi; j += i)
                    isprime[j] = false;
        }

        priority_queue<pr, vector<pr>, greater<pr>> minpq;
        auto cmp = [](const pr &a, const pr &b)
        {
            return a.first < b.first || (a.first == b.first && a.second > b.second);
        };
        priority_queue<pr, vector<pr>, decltype(cmp)> maxpq(cmp);

        int ans = 0, l = 0;
        deque<int> primeIndices;

        for (int i = 0; i < n; i++)
        {
            if (isprime[nums[i]])
            {
                minpq.push({nums[i], i});
                maxpq.push({nums[i], i});
                primeIndices.push_back(i); 
            }

            while (!minpq.empty() && minpq.top().second < l)
                minpq.pop();
            while (!maxpq.empty() && maxpq.top().second < l)
                maxpq.pop();

            while (!minpq.empty() && !maxpq.empty() && abs(maxpq.top().first - minpq.top().first) > k)
            {
                if (isprime[nums[l]])
                {
                    if (!primeIndices.empty() && primeIndices.front() == l)
                        primeIndices.pop_front(); 
                }
                l++;

                while (!minpq.empty() && minpq.top().second < l)
                    minpq.pop();
                while (!maxpq.empty() && maxpq.top().second < l)
                    maxpq.pop();
            }
            if (primeIndices.size() >= 2)
            {
                int second_last_index = primeIndices[primeIndices.size() - 2];
                ans += (second_last_index - l + 1);
            }
        }

        return ans;
    }
};