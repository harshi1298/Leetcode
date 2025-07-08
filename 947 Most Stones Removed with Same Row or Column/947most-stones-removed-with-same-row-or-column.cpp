#include <bits/stdc++.h>
using namespace std;
class Dsu
{
private:
    vector<int> par, rank;

public:
    Dsu(int n)
    {
        par.resize(n);
        rank.resize(n, 1);
        for (int i = 0; i < n; i++)
            par[i] = i;
    }
    int find(int x)
    {
        if (par[x] == x)
            return x;
        return par[x] = find(par[x]);
    }
    bool unite(int u, int v)
    {
        int paru = find(u);
        int parv = find(v);
        if (paru == parv)
            return false;
        if (rank[paru] < rank[parv])
        {
            par[paru] = parv;
        }
        else if (rank[paru] > rank[parv])
        {
            par[parv] = paru;
        }
        else
        {
            par[paru] = parv;
            rank[parv]++;
        }
        return true;
    }
};
class Solution
{
public:
    int removeStones(vector<vector<int>> &stones)
    {
        int n = stones.size();
        Dsu dsu(n);
        int ans = n;
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (stones[i][0] == stones[j][0] || stones[i][1] == stones[j][1])
                {
                    if (dsu.unite(i, j))
                        ans--;
                }
            }
        }
        return n - ans;
    }
};