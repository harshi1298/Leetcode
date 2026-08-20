class Solution {
public:
    int minMoves(vector<int>& nums, int limit) {
        int n=nums.size();
        vector<int>diff(2*limit+2,0);
        for(int i=0;i<n/2;i++){
            int maxi=max(nums[i],nums[n-i-1]);
            int mini=min(nums[i],nums[n-i-1]);
            int maxval=maxi+limit;
            int minval=mini+1;
            diff[0]+=2;
            diff[2*limit+1]-=2;
            diff[minval]+=-1;
            diff[maxval+1]-=-1;
            int sum=nums[i]+nums[n-i-1];
            diff[sum]+=-1;
            diff[sum+1]-=-1;
        }
        int ans=INT_MAX;
        for(int i=1;i<=2*limit;i++){
            diff[i]+=diff[i-1];
            ans=min(ans,diff[i]);
        }
        return ans;
    }
};