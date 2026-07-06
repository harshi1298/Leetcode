class Solution {
public:
    int maxValidPairSum(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>suff(n+1,0);
        for(int i=n-1;i>=0;i--){
            suff[i]=max(suff[i+1],nums[i]);
        }
        int ans=0;
        for(int i=0;i<n-k;i++){
            ans=max(ans,nums[i]+suff[i+k]);
        }
        return ans;
    }
};