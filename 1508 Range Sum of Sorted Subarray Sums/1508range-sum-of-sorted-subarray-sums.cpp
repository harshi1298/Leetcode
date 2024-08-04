class Solution {
    int x=1e9+7;
private:
   void solve(vector<int> nums,vector<int> &ans,int i){
           for(int j=0;j<nums.size();j++){
            int sum=0;
            for(int k=j;k<=i && k<nums.size();k++){
                sum+=nums[k];
                sum=sum%x;
            }
            if(sum>0)
            ans.push_back(sum);
           }
     }
public:
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        vector<int> ans;
        for(int i=0;i<nums.size();i++){
            solve(nums,ans,i);
        }
        sort(ans.begin(),ans.end());
        int know=0;
        for(int i=left-1;i<right;i++){
             know+=ans[i];
             know=know%x;
        }
        return know;
    }
};