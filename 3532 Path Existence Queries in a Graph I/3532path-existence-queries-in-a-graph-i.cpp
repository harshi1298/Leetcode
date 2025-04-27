
class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& que) {
        // DisjountSet ds(n);
        // for(int i=0;i<n;i++){
            
        // }
        vector<pair<int,int>> vec;
        for(int i=0;i<n;i++){
            vec.push_back({nums[i],i});
        }
        sort(vec.begin(),vec.end());
        int g=0;
        vector<int> group(n,-1);
        group[vec[0].second]=g;
        for(int i=1;i<n;i++){
            if(vec[i].first-vec[i-1].first>maxDiff) {
                g++;
            }
            group[vec[i].second]=g;
        }
        vector<bool>ans(que.size());
        int i=0;
        for(auto it: que){
            ans[i]=group[it[0]]==group[it[1]];
            i++;
        }
        return ans;
    }
};