#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
class Solution
{
public:
    vector<long long> unmarkedSumArray(vector<int> &nums, vector<vector<int>> &queries)
    {
        int n = nums.size();
        unordered_map<int, int> mapp;
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        long long sum = 0;
        for (int i = 0; i < n; i++)
        {
            pq.push(make_pair(nums[i], i));
            sum += nums[i];
        }
        vector<long long> ans;
        for (auto it : queries)
        {
            int ind = it[0];
            int k = it[1];
            if (mapp.find(ind) == mapp.end())
                sum -= nums[ind];
            mapp[ind] = 1;
            while (k && !pq.empty())
            {
                auto [val, i] = pq.top();
                pq.pop();
                if (mapp.find(i) == mapp.end())
                {
                    k--;
                    sum -= val;
                }
                mapp[i] = 1;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};