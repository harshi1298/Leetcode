class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<vector<int>>adj(n);
        vector<int>indegree(n);
        for(auto it : relations){
            int u=it[0]-1,v=it[1]-1;
            adj[u].push_back(v);
            indegree[v]++;
        }
        queue<int>que;
        vector<int>dp(n);
        for(int i=0;i<n;i++){
           if(indegree[i]==0){
            que.push(i);
            dp[i]=time[i];
           }
        }
        while(!que.empty()){
            auto v=que.front();
            que.pop();
            for(auto it : adj[v]){
                dp[it]=max(dp[it],dp[v]+time[it]);
                indegree[it]--;
                if(indegree[it]==0)que.push(it);
            }
        }
        return *max_element(dp.begin(),dp.end());
    }
};