class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int l=0,r=0,ans=0;
        int k=nums.size()-1;
        while(r<=k){
            if(nums[r]){
                ans=max(ans,r-l+1);
                r++;
            }
            else{
                r++;
                l=r;
            }
        }
        return ans;
    }
};