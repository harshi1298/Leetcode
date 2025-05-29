class Solution {
private:
    void dfs(vector<vector<int>>& adj, int node, int par, int depth, vector<int>& dep, int& even, int& odd) {
        dep[node] = depth;
        if (depth % 2 == 0) even++;
        else odd++;

        for (int nei : adj[node]) {
            if (nei != par) {
                dfs(adj, nei, node, depth + 1, dep, even, odd);
            }
        }
    }

public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n = edges1.size() + 1;
        int m = edges2.size() + 1;

        vector<vector<int>> adj1(n), adj2(m);
        for (auto& e : edges1) {
            adj1[e[0]].push_back(e[1]);
            adj1[e[1]].push_back(e[0]);
        }
        for (auto& e : edges2) {
            adj2[e[0]].push_back(e[1]);
            adj2[e[1]].push_back(e[0]);
        }

        vector<int> depth1(n), depth2(m);
        int even2 = 0, odd2 = 0;
        dfs(adj2, 0, -1, 0, depth2, even2, odd2);

        int even1 = 0, odd1 = 0;
        dfs(adj1, 0, -1, 0, depth1, even1, odd1);
        cout<<even1<< " "<<odd1<<endl;
        cout<<even2<< " "<<odd2<<endl;
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            if (depth1[i] % 2 == 0) {
                ans[i] = even1+max(even2,odd2);
            } else {
                ans[i] = odd1+max(even2,odd2);
            }
        }

        return ans;
    }
};
