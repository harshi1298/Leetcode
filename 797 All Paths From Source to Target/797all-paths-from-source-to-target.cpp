class Solution {
private:
   void solve(vector<vector<int>>& graph,int ind, vector<vector<int>>&ans,vector<int>ans1){
    if(ind==graph.size()-1){
        ans.push_back(ans1);
        return;
    }
    for(int i=0;i<graph[ind].size();i++){
        ans1.push_back(graph[ind][i]);
        solve(graph,graph[ind][i],ans,ans1);
        ans1.pop_back();
    }
   }
public:
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        vector<vector<int>>ans;
        vector<int>ans1;
        ans1.push_back(0);
        solve(graph,0,ans,ans1);
        return ans;
    }
};