
#include <bits/stdc++.h>
using namespace std;
#define pr pair<string, int>
class Solution
{
private:
    unordered_map<string, vector<string>> par;
    set<vector<string>> check;
    vector<vector<string>>result;
    void construct(string s, vector<string> arr)
    {
        if (s == "")
        {
            reverse(arr.begin(),arr.end());
            if(check.find(arr)==check.end()){
                check.insert(arr);
                result.push_back(arr);
            }
            reverse(arr.begin(),arr.end());
            return;
        }
        arr.push_back(s);
        for (auto it : par[s])
        {
            construct(it, arr);
        }
        arr.pop_back();
    }

public:
    vector<vector<string>> findLadders(string bw, string ew, vector<string> &words)
    {
        words.push_back(bw);
        unordered_set<string> st;
        unordered_map<string, vector<string>> adj;
        for (auto it : words)
        {
            st.insert(it);
        }
        for (auto s : words)
        {
            int k = s.length();
            for (int i = 0; i < k; i++)
            {
                for (int j = 0; j < 26; j++)
                {
                    if (s[i] == j + 'a')
                        continue;
                    string temp = s;
                    temp[i] = j + 'a';
                    if (st.find(temp) != st.end())
                    {
                        adj[s].push_back(temp);
                    }
                }
            }
        }
        // for(auto it : adj){
        //     cout<<it.first<<endl; 
        //     for( auto s : it.second)cout<<s<<" ";
        //     cout<<endl;
        // } 
        queue<pr> que;
        par[bw] = {""};
        que.push(make_pair(bw, 1));
        unordered_map<string, int> vis;
        vis[bw] = 1;
        int ans = INT_MAX;
        while (!que.empty())
        {
            auto [s, d] = que.front();
            que.pop();
            if (s == ew)
            {
                ans = min(ans, d);
            }
            for (auto it : adj[s])
            {
                if (vis.find(it)==vis.end() ||vis[it]>d+1)
                {
                    par[it].clear();
                    par[it].push_back(s);
                    vis[it] = d+1;
                    que.push(make_pair(it, d + 1));
                }
                else if (vis[it]==d+1)
                {
                    par[it].push_back(s);
                }
            }
        }
        construct(ew,{});
        return result;
    }
};