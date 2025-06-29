#include <bits/stdc++.h>
using namespace std;

class DSU
{
    vector<int> parent, rank;

public:
    DSU(int n)
    {
        parent.resize(n);
        rank.resize(n, 0);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int find(int x)
    {
        if (parent[x] != x)
            parent[x] = find(parent[x]);
        return parent[x];
    }
    bool unite(int x, int y)
    {
        int px = find(x), py = find(y);
        if (px == py)
            return false;
        if (rank[px] < rank[py])
            parent[px] = py;
        else if (rank[px] > rank[py])
            parent[py] = px;
        else
        {
            parent[py] = px;
            rank[px]++;
        }
        return true;
    }
};

class Solution
{
public:
    int maxStability(int n, vector<vector<int>> &edges, int k)
    {
        sort(edges.begin(), edges.end(), [&](auto &a, auto &b)
             { return a[2] > b[2]; });
        int ans = INT_MAX;
        int count = 0;
        DSU dsu(n);
        for (auto &e : edges)
        {
            if (e[3] == 1)
            {
                if (!dsu.unite(e[0], e[1]))
                    return -1;
                ans = min(ans, e[2]);
                count++;
            }
        }
        vector<int> temp;
        for (auto &e : edges )
        {
            if (e[3] == 0 && dsu.unite(e[0], e[1]))
            {
                temp.push_back(e[2]);
                count++;
            }
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        for (auto x : temp)
            pq.push({x, 0});

        while (k > 0 && !pq.empty())
        {
            auto [val, used] = pq.top();
            pq.pop();
            if (used == 0)
            {
                pq.push({val * 2, 1});
                k--;
            }
            else
            {
                pq.push({val, 1});
                break;
            }
        }

        if (count != n - 1)
            return -1;
        if (pq.empty())
            return ans;
        return min(ans, pq.top().first);
    }
};