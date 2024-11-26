class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        vector<int>indegree(n);
        int count=0;
        int ans=-1;
        for(auto edge :edges){
          indegree[edge[1]]++;
        }
        for(int j=0;j<n;j++){
            if(indegree[j]==0){
                count++;
                ans=j;
                if(count==2)return -1;
            }
        }
        return ans;
    }
};