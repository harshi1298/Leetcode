class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int ans=1;
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                 if(nums[j]>nums[j-1]){
                    ans=max(ans,j-i+1);
                 }
                 else break;
            }
        }
        for(int i=0;i<nums.size();i++){
            for(int j=i+1;j<nums.size();j++){
                 if(nums[j]<nums[j-1]){
                    ans=max(ans,j-i+1);
                 }
                 else break;
            }
        }
        return ans;
    }
};