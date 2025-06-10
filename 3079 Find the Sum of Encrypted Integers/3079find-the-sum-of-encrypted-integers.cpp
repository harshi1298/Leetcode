#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int newnumber(int x)
    {
        int newn = 0;
        int maxi = 0;
        int c = 0;
        while (x)
        {
            maxi = max(maxi, x % 10);
            x /= 10;
            c++;
        }
        while (c)
        {
            newn = newn * 10 + maxi;
            c--;
        }
        return newn;
    }

public:
    int sumOfEncryptedInt(vector<int> &nums)
    {
        int ans = 0;
        for (auto it : nums)
        {
            ans += newnumber(it);
        }
        return ans;
    }
};