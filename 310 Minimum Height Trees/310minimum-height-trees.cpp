class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n <= 2) {
            vector<int> ans;
            for (int i = 0; i < n; i++) ans.push_back(i);
            return ans;
        }

        vector<vector<int>> adj(n);
        vector<int> degree(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
            degree[e[0]]++;
            degree[e[1]]++;
        }

        queue<int> q;
        for (int i = 0; i < n; i++) {
            if (degree[i] == 1) q.push(i);
        }

        int remaining = n;

        while (remaining > 2) {
            int sz = q.size();
            remaining -= sz;

            for (int i = 0; i < sz; i++) {
                int leaf = q.front(); q.pop();

                for (int nei : adj[leaf]) {
                    degree[nei]--;
                    if (degree[nei] == 1) {
                        q.push(nei);
                    }
                }
            }
        }

        vector<int> ans;
        while (!q.empty()) {
            ans.push_back(q.front());
            q.pop();
        }

        return ans;
    }
};
