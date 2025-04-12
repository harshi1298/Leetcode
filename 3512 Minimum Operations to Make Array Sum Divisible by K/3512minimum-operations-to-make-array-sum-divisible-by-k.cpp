class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int ans=0;
        int size=nums.size();
        for(int i=0;i<size;i++){
            ans+=(nums[i]);
        }
        return ans%k;
    }
};