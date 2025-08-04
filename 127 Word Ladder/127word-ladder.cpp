
#include <bits/stdc++.h>
using namespace std;
#define pr pair<string, int>
class Solution {
public:
    int ladderLength(string bw, string ew, vector<string>& words) {
        words.push_back(bw);
        unordered_set<string> st;
        for (auto it : words) {
            st.insert(it);
        }
        unordered_map<string, vector<string>> adj;
        int n = words.size();
        for (auto s : words) {
            int k = s.length();
            for (int i = 0; i < k; i++) {
                for (int j = 0; j < 26; j++) {
                    if (s[i] == j + 'a')
                        continue;
                    string temp = s;
                    temp[i] = j + 'a';
                    if (st.find(temp) != st.end()) {
                        adj[s].push_back(temp);
                        adj[temp].push_back(temp);
                    }
                }
            }
        }
        int ans = INT_MAX;
        queue<pr> que;
        que.push({bw, 1});
        unordered_map<string,int>vis;
        while (!que.empty()) {
            auto [str, val] = que.front();
            vis[str]=1;
            que.pop();
            if (str == ew) {
                ans = min(ans, val);
                continue;
            }
            for (auto it : adj[str]) {
                if(!vis[it])
                que.push({it, val + 1});
            }
        }
        return ans==INT_MAX?0:ans;
    }
};