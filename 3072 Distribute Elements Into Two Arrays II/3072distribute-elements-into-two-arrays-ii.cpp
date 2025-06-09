#include <bits/stdc++.h>
using namespace std;

void update(int i, vector<int> &bit)
{
    int n = bit.size();
    for (; i < n; i += (i & -i))
    {
        bit[i] += 1;
    }
}

int sum(int i, vector<int> &bit)
{
    int ans = 0;
    for (; i > 0; i -= (i & -i))
    {
        ans += bit[i];
    }
    return ans;
}

class Solution
{
public:
    vector<int> resultArray(vector<int> &nums)
    {
        int n = nums.size();

        vector<int> sorted_nums = nums;
        sort(sorted_nums.begin(), sorted_nums.end());
        unordered_map<int, int> compress;
        int idx = 1;
        int maxi=nums[n-1];
        for (int val : sorted_nums)
        {
            if (compress.find(val) == compress.end())
                compress[val] = idx++;
        }

        int size = idx + 2;
        vector<int> tree1(size, 0), tree2(size, 0), arr1, arr2;

        update(compress[nums[0]], tree1);
        update(compress[nums[1]], tree2);
        arr1.push_back(nums[0]);
        arr2.push_back(nums[1]);

       for (int i = 2; i < n; i++)
{
    int cval = compress[nums[i]];
    
    int total1 = sum(size - 1, tree1);
    int total2 = sum(size - 1, tree2);
    int greater1 = total1 - sum(cval, tree1);
    int greater2 = total2 - sum(cval, tree2);

    if (greater1 > greater2)
    {
        arr1.push_back(nums[i]);
        update(cval, tree1);
    }
    else if (greater1 < greater2)
    {
        arr2.push_back(nums[i]);
        update(cval, tree2);
    }
    else
    {
        if (arr1.size() <= arr2.size())
        {
            arr1.push_back(nums[i]);
            update(cval, tree1);
        }
        else
        {
            arr2.push_back(nums[i]);
            update(cval, tree2);
        }
    }
}


        for (int x : arr2)
            arr1.push_back(x);

        return arr1;
    }
};
