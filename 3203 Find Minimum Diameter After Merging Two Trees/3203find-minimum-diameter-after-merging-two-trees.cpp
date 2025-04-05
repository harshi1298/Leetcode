class Solution {
        pair<int, int> bfs(int start, vector<vector<int>>& adj) {
        vector<int> dist(adj.size(), -1);
        queue<int> q;
        q.push(start);
        dist[start] = 0;
        int farthestNode = start;

        while (!q.empty()) {
            int node = q.front(); q.pop();
            for (int neighbor : adj[node]) {
                if (dist[neighbor] == -1) {
                    dist[neighbor] = dist[node] + 1;
                    q.push(neighbor);
                    if (dist[neighbor] > dist[farthestNode]) {
                        farthestNode = neighbor;
                    }
                }
            }
        }

        return {farthestNode, dist[farthestNode]};
    }
    int finddiameter(vector<vector<int>>& adj) {
        auto [farthest1, _] = bfs(0, adj);
        auto [farthest2, diameter] = bfs(farthest1, adj);
        return diameter;
    }
public:
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int size1=edges1.size()+1,size2=edges2.size()+1;
        vector<vector<int>>adj1(size1),adj2(size2);
        for(auto it : edges1){
           adj1[it[0]].push_back(it[1]);
           adj1[it[1]].push_back(it[0]);
        }
        for(auto it : edges2){
           adj2[it[0]].push_back(it[1]);
           adj2[it[1]].push_back(it[0]);
        }
        int d1=finddiameter(adj1);
        int d2=finddiameter(adj2);
        cout<<d1<<" "<<d2<<" ";
        return max({d1,d2, (int)(ceil(d1/2.0)+ceil(d2/2.0)+1)});
    }
};