class Solution {
private:
    unordered_map<long long, int> memo;
    long long getKey(int node, int k, int sum) {
        return (1LL * node << 40) | (1LL * k << 20) | sum;
    }

    int dfs(int node, int k, int sum, int t, const vector<vector<pair<int, int>>>& adj) {
        if (sum >= t) return -1;
        if (k == 0) return 0;
        long long key = getKey(node, k, sum);
        if (memo.count(key)) return memo[key];
        int ans = -1;
        for (auto& [nei, wt] : adj[node]) {
            if (sum + wt < t) {
                int temp = dfs(nei, k - 1, sum + wt, t, adj);
                if (temp != -1)
                    ans = max(ans, wt + temp);
            }
        }
        return memo[key] = ans;
    }

public:
    int maxWeight(int n, vector<vector<int>>& edges, int k, int t) {
        vector<vector<pair<int, int>>> adj(n);
        for (auto& e : edges)
            adj[e[0]].emplace_back(e[1], e[2]);

        int res = -1;
        for (int i = 0; i < n; ++i) {
            res = max(res, dfs(i, k, 0, t, adj));
        }
        return res;
    }
};
