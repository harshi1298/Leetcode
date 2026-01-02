class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {
        int n=nums.size();
        for(int i=1;i<=3;i++){
            for(int j=0;j<n-i;j++){
                if(nums[j]==nums[i+j])return nums[j];
            }
        }
        return -1;
    }
};