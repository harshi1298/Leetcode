class Solution {
public:
    int minimumVisitedCells(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<set<int>> rows(n), cols(m);
        for (int i = 0; i < n; i++) 
            for (int j = 0; j < m; j++)
                rows[i].insert(j), cols[j].insert(i);

        queue<pair<int,int>> q;
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 1;
        q.push({0,0});
        rows[0].erase(0);
        cols[0].erase(0);

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            int d = dist[i][j];

            // Move right within row i
            auto it = rows[i].lower_bound(j + 1);
            while (it != rows[i].end() && *it <= j + grid[i][j]) {
                int nj = *it;
                dist[i][nj] = d + 1;
                q.push({i, nj});
                cols[nj].erase(i);
                it = rows[i].erase(it);
            }
            auto it2 = cols[j].lower_bound(i + 1);
            while (it2 != cols[j].end() && *it2 <= i + grid[i][j]) {
                int ni = *it2;
                dist[ni][j] = d + 1;
                q.push({ni, j});
                rows[ni].erase(j);
                it2 = cols[j].erase(it2);
            }
        }

        return dist[n-1][m-1] == INT_MAX ? -1 : dist[n-1][m-1];
    }
};