#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    long long mode = 1e9 + 7;

public:
    int specialTriplets(vector<int> &nums)
    {
        unordered_map<long long, long long> mapp1;
        unordered_map<long long, long long> mapp2;
        long long n = nums.size();
        for (long long i = 1; i < n; i++)
        {
            mapp1[nums[i]]++;
        }
        mapp2[nums[0]]++;
        long long ans = 0;
        for (long long i = 1; i < n-1; i++)
        {
            mapp1[nums[i]]--;
            ans += (mapp1[nums[i]*2]  * mapp2[nums[i]*2]);
            // cout<<mapp1[nums[i]*2]<<" "<<mapp2[nums[i]*2]<<" "<<nums[i]<<endl;
            mapp2[nums[i]]++;
            ans %= mode;
        }
        return (int)ans;
    }
};