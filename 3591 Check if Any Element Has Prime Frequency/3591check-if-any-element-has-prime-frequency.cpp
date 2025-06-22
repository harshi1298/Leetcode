#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, int>
class Solution
{
private:
    bool isprime(int n)
    {
        if (n < 2)
            return false;
        for (int i = 2; i * i <= n; i++)
        {
            if (n % i == 0)
                return false;
        }
        return true;
    }

public:
    bool checkPrimeFrequency(vector<int> &nums)
    {
        unordered_map<int, int> mapp;
        int n = nums.size();
        for (int i = 0; i < n; i++)
        {
            mapp[nums[i]]++;
        }
        for (auto [key, f] : mapp)
        {
            if (isprime(f))
                return true;
        }
        return false;
    }
};