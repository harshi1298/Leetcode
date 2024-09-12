class Solution {
public:
    bool canJump(vector<int>& nums) {
        long long maxjump=0;
        int i=0,j=0;
        while(j<nums.size()-1){
            if((maxjump<(nums[j]+j)) || (j>=maxjump)){
                maxjump=nums[j]+j;
                i=j;
            }
            if(nums[j]==0 && maxjump<=j)return false;
            j++;
        }
        return true;
    }
};