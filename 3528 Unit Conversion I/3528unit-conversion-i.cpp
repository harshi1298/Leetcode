class Solution {
private:
    const int modulo = 1e9 + 7;

    void dfs(int i, int n, vector<long long>& ans, long long temp,
             vector<vector<pair<int, int>>>& adj) {
        ans[i] = temp;
          if (i == n+1){
              return ;
          }
        for (auto it : adj[i]) {
            dfs(it.first, n, ans, (temp * it.second) % modulo, adj);
        }
    }

public:
    vector<int> baseUnitConversions(vector<vector<int>>& conversions) {
        int n = conversions.size();
        vector<vector<pair<int, int>>> adj(n+1);

        for (int i = 0; i <n; i++) {
            int u = conversions[i][0];
            int v = conversions[i][1];
            int val = conversions[i][2];
            adj[u].push_back({v, val});
        }

        vector<long long> ans(n+1, 0);
        dfs(0, n, ans, 1, adj);

        vector<int> result(n+1);
        for (int i = 0; i <= n; i++) {
            result[i] = ans[i] % modulo;
        }
        return result;
    }
};
