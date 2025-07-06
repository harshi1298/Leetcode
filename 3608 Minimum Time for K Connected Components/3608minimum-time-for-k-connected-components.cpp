#include <bits/stdc++.h>
using namespace std;

class DSU
{
public:
    vector<int> parent;
    DSU(int n)
    {
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    void unite(int x, int y)
    {
        int xr = find(x);
        int yr = find(y);
        if (xr != yr)
            parent[xr] = yr;
    }
};

class Solution
{
public:
    int minTime(int n, vector<vector<int>> &edges, int k)
    {

        int start = 0, end = 0;
        for (auto &e : edges)
            end = max(end, e[2]);

        int ans = -1;

        while (start <= end)
        {
            int mid = start + (end - start) / 2;

            DSU dsu(n);
            for (auto &e : edges)
            {
                if (e[2] > mid)
                {
                    dsu.unite(e[0], e[1]);
                }
            }
            unordered_set<int> st;
            for (int i = 0; i < n; i++)
            {
                st.insert(dsu.find(i));
            }
            int count = st.size();

            if (count >= k)
            {
                ans = mid;
                end = mid - 1;
            }
            else
            {
                start = mid + 1;
            }
        }
        return ans;
    }
};
