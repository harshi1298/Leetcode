class Solution {
private:
    int solve( vector<vector<int>>&adj,int n){
        vector<int>dis(n,INT_MAX);
        queue<int>que;
        que.push(0);
        dis[0]=0;
        while(!que.empty()){
            int p=que.front();
            que.pop();
            for(auto j:adj[p]){
                if(dis[j]>dis[p]+1){
                    dis[j]=dis[p]+1;
                    que.push(j);
                }
            }
        }
        return dis[n-1];
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>>adj(n);
        for(int i=0;i<n-1;i++){
            adj[i].push_back(i+1);
        }
        vector<int>ans;
        for(auto q :queries){
            adj[q[0]].push_back(q[1]);
            ans.push_back(solve(adj,n));
        }
        return ans;
    }
};