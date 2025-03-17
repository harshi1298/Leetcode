class Solution {
private:
    set<vector<int>>st;
    void solve(vector<int>&nums,vector<int> &tmp,vector<int>&vis){
        if(tmp.size()==nums.size()){
            st.insert(tmp);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!vis[i]){
                vis[i]=1;
                tmp.push_back(nums[i]);
                solve(nums,tmp,vis);
                tmp.pop_back();
                vis[i]=0;
            }
        }
    }
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>vis(nums.size(),0);
        vector<int> tmp;
        solve(nums,tmp,vis);
      vector<vector<int>> ans(st.begin(), st.end());
        return ans;
    }
};