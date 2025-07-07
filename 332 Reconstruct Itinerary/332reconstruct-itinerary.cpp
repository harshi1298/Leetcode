#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    vector<string> findItinerary(vector<vector<string>>& tickets)
    {
        unordered_map<string, multiset<string>> graph;
        for (auto &ticket : tickets)
        {
            graph[ticket[0]].insert(ticket[1]);
        }
        vector<string> ans;
        dfs("JFK", graph, ans);
        reverse(ans.begin(),ans.end());
        return ans;
    }

private:
    void dfs(const string &start, unordered_map<string, multiset<string>> &graph, vector<string> &ans)
    {
        while (graph[start].size())
        {
            string next = *graph[start].begin();
            graph[start].erase(graph[start].begin());
            dfs(next, graph, ans);
        }
        ans.push_back(start);
    }
};