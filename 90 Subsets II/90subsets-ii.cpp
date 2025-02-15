class Solution {
private:
   void solve(vector<int> nums,vector<vector<int>> &ans,vector<int> ans1,int i){
        if(i>=nums.size()){
            ans.push_back(ans1);
             return ;}
        solve(nums,ans,ans1,i+1);
        ans1.push_back(nums[i]);
        solve(nums,ans,ans1,i+1);
   }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector <int>> ans;
        vector<int> ans1;
        int index=0;
        solve(nums,ans,ans1,index);
        set<vector<int>> s;
        for(int i=0;i<ans.size();i++) s.insert(ans[i]);
         vector<vector<int> >ans2(s.begin(),s.end());
         return ans2;
    }
};