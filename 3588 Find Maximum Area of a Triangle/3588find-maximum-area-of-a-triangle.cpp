#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maxArea(vector<vector<int>> &coords)
    {
        map<long long, vector<long long>> xGroup, yGroup;
        long long n = coords.size();

        for (auto &p : coords)
        {
            long long x = p[0], y = p[1];
            yGroup[y].push_back(x);
            xGroup[x].push_back(y);
        }

        long long maxArea2 = 0;

        for (auto &it : xGroup)
        {
            sort(it.second.begin(), it.second.end());
        }

        for (auto &it : yGroup)
        {
            sort(it.second.begin(), it.second.end());
        }

        for (auto &it : xGroup)
        {
            long long x = it.first;
            long long a = it.second[it.second.size() - 1] - it.second[0];

            long long h1 = abs(xGroup.begin()->first - x);
            long long h2 = abs(xGroup.rbegin()->first - x);
            long long h = max(h1, h2);
            // cout<<h<<a<<"x"<<endl;
            maxArea2 = max(maxArea2, h * a);
        }

        for (auto &it : yGroup)
        {
            long long y = it.first;
            long long a = it.second[it.second.size() - 1] - it.second[0];

            long long h1 = abs(yGroup.begin()->first - y);
            long long h2 = abs(yGroup.rbegin()->first - y);
            long long h = max(h1, h2);
             // cout<<h<<a<<endl;
            maxArea2 = max(maxArea2, h * a);
        }

        return maxArea2 == 0 ? -1 : maxArea2;
    }
};
