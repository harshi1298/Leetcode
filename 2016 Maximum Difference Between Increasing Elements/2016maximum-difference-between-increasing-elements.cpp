class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int mini=nums[0],n=nums.size();
        int ans=INT_MIN;
        for(int i=1;i<n;i++){
            ans=max(ans,nums[i]-mini);
            mini=min(mini,nums[i]);
        }
        return ans>0?ans:-1;
    }
};