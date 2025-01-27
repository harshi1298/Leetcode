class Solution {
private:
    bool check(int i, int j, vector<vector<int>>& graph, vector<int>& vis) {
        vis[i] = 1;
        for (auto& it : graph[i]) {
            if (it == j) return true;
            if (vis[it]==0) {
                if (check(it, j, graph, vis)) return true; 
            }
        }
        return false;
    }
    stack<int> st;
    void dfs(vector<vector<int>>& graph, vector<int>& vis, int i) {
        vis[i] = 1; 
        for (auto& it : graph[i]) {
            if (vis[it] == 0) { 
                dfs(graph, vis, it);
            }
        }
        st.push(i); 
    }
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& q) {
        vector<int> vis(n, 0); 
        vector<vector<int>> graph(n);
        for (auto& p : pre) {
            graph[p[0]].push_back(p[1]);
        }
        for (int i = 0; i < n; i++) {
            if (vis[i] == 0) { 
                dfs(graph, vis, i);
            }
        }
        unordered_map<int, int> mapp;
        int idx = 0;
        while (!st.empty()) {
            mapp[st.top()] = idx++;
            st.pop();
        }

        vector<bool> ans;
        for (auto& qItem : q) {
            vector<int> vis1(n, 0);
            bool temp = check(qItem[0], qItem[1], graph, vis1);
            if (temp && mapp[qItem[0]] < mapp[qItem[1]]) {
                ans.push_back(true);
            } else {
                ans.push_back(false);
            }
        }

        return ans;
    }
};
