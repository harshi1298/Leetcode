class Solution {
public:
    int maximumStrongPairXor(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans=0,i=0;
        for(auto it : nums){
            auto last=upper_bound(nums.begin(),nums.end(),2*it)-nums.begin();
            last--;
            for(int j=i;j<=last;j++){
               ans=max(ans,it^nums[j]);
            }
            i++;
        }
        return ans;
    }
};