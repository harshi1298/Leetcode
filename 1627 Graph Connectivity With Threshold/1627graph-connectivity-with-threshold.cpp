#include <bits/stdc++.h>
using namespace std;
class Dsu
{
private:
    vector<int> par;
    vector<int> rank;

public:
    Dsu(int n)
    {
        par.resize(n);
        for (int i = 0; i <  n; i++)
        {
            par[i] = i;
        }
        rank.resize(n, 1);
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    void unite(int u, int v)
    {
        int paru = find(u);
        int parv = find(v);
        if (paru == parv)
        {
            return;
        }
        else if (rank[paru] < rank[parv])
        {
            par[parv] = paru;
        }
        else if (rank[paru] > rank[parv])
        {
            par[paru] = parv;
        }
        else
        {
            par[paru] = parv;
            rank[parv]++;
        }
    }
};
class Solution
{
public:
    vector<bool> areConnected(int n, int threshold, vector<vector<int>> &queries)
    {
        Dsu dsu(n + 1);
        for (int i = threshold + 1; i <= n; i++)
        {
            for (int j = i + i; j <= n; j += i)
            {
                dsu.unite(i, j);
            }
        }
        vector<bool> ans;
        for (auto &it : queries)
        {
            if (dsu.find(it[0]) == dsu.find(it[1]))
            {
                ans.push_back(true);
            }
            else
            {
                ans.push_back(false);
            }
        }
        return ans;
    }
};