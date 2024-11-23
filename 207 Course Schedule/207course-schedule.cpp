class Solution {
public:
    bool canFinish(int size, vector<vector<int>>& pre) {
        vector<vector<int>>adj(size);
        for(int i=0;i<pre.size();i++){
            adj[pre[i][1]].push_back(pre[i][0]);
        }
       vector<int>indegree(size,0);
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
    return ans.size()==size;
    }
};