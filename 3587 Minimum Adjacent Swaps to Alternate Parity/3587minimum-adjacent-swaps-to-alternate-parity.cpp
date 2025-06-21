#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minSwaps(vector<int> &nums)
    {
        int n = nums.size();
        int evenCount = 0, oddCount = 0;
        for (int num : nums)
        {
            if (num % 2 == 0)
                evenCount++;
            else
                oddCount++;
        }
        if (abs(evenCount - oddCount) > 1)
            return -1;

        int res = INT_MAX;
        if (evenCount >= oddCount)
        {
            int count = 0;
            for (int i = 0, j = 0; i < n; i += 2)
            {
                while (j < n && nums[j] % 2 != 0)
                    j++;
                if (j < n)
                {
                    count += abs(i - j);
                    j++;
                }
            }
            res = min(res, count);
        }
        if (oddCount >= evenCount)
        {
            int count = 0;
            for (int i = 0, j = 0; i < n; i += 2)
            {
                while (j < n && nums[j] % 2 != 1)
                    j++;
                if (j < n)
                {
                    count += abs(i - j);
                    j++;
                }
            }
            res = min(res, count);
        }

        return res;
    }
};
