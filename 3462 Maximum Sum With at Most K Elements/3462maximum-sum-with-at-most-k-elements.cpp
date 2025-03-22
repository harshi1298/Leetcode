class Solution {
public:
    long long maxSum(vector<vector<int>>& grid, vector<int>& limits, int k) {
        int n=grid.size();
        int m=grid[0].size();
        for(int i=0;i<n;i++){
            sort(grid[i].begin(),grid[i].end(),[&](auto a, auto b){
                return a>b;
            });
        }
        priority_queue<int>pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<limits[i];j++){
                pq.push(grid[i][j]);
            }
        }
        int i=0;
        long long ans=0;
        while(!pq.empty() && i<k){
             ans+=pq.top();
             pq.pop();
             i++;
        }
        return ans;
    }
};