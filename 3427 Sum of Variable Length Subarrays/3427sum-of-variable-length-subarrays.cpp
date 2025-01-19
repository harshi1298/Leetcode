class Solution {
public:
    int subarraySum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int i=0;i<n;i++){
            int j=max(0,i-nums[i]);
            while(j<=i){
                ans+=nums[j++];
            }
        }
        return ans;
    }
};