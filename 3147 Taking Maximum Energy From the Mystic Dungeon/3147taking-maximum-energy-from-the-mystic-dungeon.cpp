class Solution {
public:
    int maximumEnergy(vector<int>& nums, int k) {
        int n=nums.size();
        int ans=INT_MIN;
        for(int i=0;i<k;i++){
            int sum=0;
            for(int j=i;j<n;j+=k){
                sum+=nums[j];
                sum=max(sum,nums[j]);
            }
            ans=max(ans,sum);
        }
        return ans;
    }
};