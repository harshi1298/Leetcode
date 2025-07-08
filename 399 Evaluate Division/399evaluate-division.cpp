#include <bits/stdc++.h>
using namespace std;
#define pr pair<string, double>
class Solution
{
public:
    vector<double> calcEquation(vector<vector<string>> &equations, vector<double> &values, vector<vector<string>> &queries)
    {
        unordered_map<string, vector<pr>> adj;
        int n = equations.size();
        for (int i = 0; i < n; i++)
        {
            adj[equations[i][0]].push_back({equations[i][1], values[i]});
            adj[equations[i][1]].push_back({equations[i][0], 1 / values[i]});
        }
        vector<double> result;
        for (auto it : queries)
        {
            string src = it[0], des = it[1];
            queue<string> que;
            que.push(src);
            unordered_map<string, pr> par;
            bool flag = 0;
            if (adj.count(src) == 0 || adj.count(des) == 0)
            {
                result.push_back(-1.0);
                continue;
            }
            while (!que.empty())
            {
                string t = que.front();
                que.pop();
                if (t == des)
                    break;
                for (auto it : adj[t])
                {
                    if (par.count(it.first) == 0)
                    {
                        par[it.first] = {t, it.second};
                        que.push(it.first);
                    }
                }
            }
            double ans = 1;
            if (par.count(des) == 0 && src!=des)
            {
                ans = -1;
            }
            else
            {
                string cur = des;
                ans = 1;
                while (cur != src)
                {
                    ans *= par[cur].second;
                    cur = par[cur].first;
                }
            }

            result.push_back(ans);
        }
        return result;
    }
};