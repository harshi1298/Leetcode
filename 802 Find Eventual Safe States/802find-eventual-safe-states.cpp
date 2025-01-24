class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int size=graph.size();
        vector<int>indegree(size,0);
        vector<vector<int>>adj(size);
        for(int i=0;i<size;i++){
            for(int j:graph[i]){
                adj[j].push_back(i);
            }
        }
        for(int i=0;i<size;i++){
         for(auto j:adj[i]){
             indegree[j]++;
         }
      }
        vector<int>ans;
        queue<int>que;
        for(int i=0;i<size;i++){
            if(indegree[i]==0)que.push(i);
        }
        while(!que.empty()){
        int k=que.front();
        ans.push_back(k);
        que.pop();
        for(auto j :adj[k]){
            indegree[j]--;
            if(indegree[j]==0)que.push(j);
        }
        }
        sort(ans.begin(),ans.end());
        return ans;
        
    }
};