#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int numBusesToDestination(vector<vector<int>> &routes, int source, int target)
    {
        if(source==target)return 0;
        unordered_set<int> busvis;
        unordered_set<int> stopvis;
        unordered_map<int, vector<int>> mapp;
        queue<pair<int, int>> que;
        int n = routes.size();
        for (int i = 0; i < n; i++)
        {
            auto it = routes[i];
            for (auto r : it)
            {
                mapp[r].push_back(i);
            }
        }
        for (auto it : mapp[source])
        {
            busvis.insert(it);
            for (auto es : routes[it])
            {
                que.push(make_pair(es, 1));
                stopvis.insert(es);
            }
        }
        int ans = INT_MAX;
        while (!que.empty())
        {
            int k = que.size();
            for (int i = 0; i < k; i++)
            {
                auto [u, d] = que.front();
                que.pop();
                if(u==target)ans=min(ans,d);
                for (auto eb : mapp[u])
                {
                    if (busvis.find(eb) == busvis.end())
                    {
                        for (auto es : routes[eb])
                        {
                
                            if (stopvis.find(es) == stopvis.end())
                            {
                                que.push(make_pair(es, d + 1));
                                stopvis.insert(es);
                            }
                        }
                        busvis.insert(eb);
                    }
                }
            }
        }
        return ans == INT_MAX ? -1 : ans;
    }
};