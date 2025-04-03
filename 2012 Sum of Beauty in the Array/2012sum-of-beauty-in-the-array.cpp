class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        int n=nums.size(),ans=0;
        vector<int>pre(n+1);
        for(int i=1;i<=n;i++){
           pre[i]=max(pre[i-1],nums[i-1]);
        }
        vector<int>suff(n+1);
        suff[n]=INT_MAX;
        for(int i=n-1;i>0;i--){
            suff[i]=min(suff[i+1],nums[i]);
        }
        for(int i=1;i<n-1;i++){
            if(pre[i]<nums[i] && suff[i+1]>nums[i])ans+=2;
            else if(nums[i]>nums[i-1] && nums[i+1]>nums[i])ans+=1;
        }
        return ans;
    }
};