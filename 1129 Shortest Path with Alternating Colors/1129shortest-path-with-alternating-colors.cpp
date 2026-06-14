class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int,int>>>adj(n);
        for(auto it : redEdges){
            int u=it[0],v=it[1];
            adj[u].push_back({v,0});
        }
        for(auto it :blueEdges){
            int u=it[0],v=it[1];
            adj[u].push_back({v,1});
        }
        vector<int>ans(n,-1);
        vector<vector<int>> vis(n, vector<int>(2, 0));
        queue<pair<int,int>>que;
        que.push({0,0});
        que.push({0,1});
        vis[0][0]=vis[0][1]=1;
        int dist=0;
        while(!que.empty()){
            int sz=que.size();
            for(int i=0;i<sz;i++){
                auto [front,col]=que.front();
                if(ans[front] == -1)
                    ans[front] = dist;
                que.pop();
                for(auto [it,ncol]:adj[front]){
                    if( vis[it][ncol] ==0 && (col !=ncol)){
                        vis[it][ncol]=1;
                        que.push({it,ncol});
                    }
                }
            }
            dist++;
        }
        return ans;
    }
};