class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n=nums.size();
        int req_sum=((n+1)*(n))/2;
        int sum=0;
        for(int i=0;i<n;i++){
            sum=sum+nums[i];
        }
        int ans=req_sum-sum;
        return ans;
    }
};