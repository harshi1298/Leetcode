#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int maxEnvelopes(vector<vector<int>> &en)
    {

        sort(en.begin(), en.end(), [](vector<int> &a, vector<int> &b)
             {
            if (a[0] == b[0]) return a[1] > b[1];
            return a[0] < b[0]; });
        vector<int> temp;
        for (auto &it : en)
        {
            int h = it[1];
            auto low = lower_bound(temp.begin(), temp.end(), h);
            if (low == temp.end())
                temp.push_back(h);
            else
                *low = h;
        }

        return temp.size();
    }
};
