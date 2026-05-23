class Solution {
public:
    int minimumSwaps(vector<int>& nums) {
        int ans=0;
        int count0=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]==0)count0++;
        }
        for(int i=0;i<n-count0;i++){
            if(nums[i]==0)
              ans++;
        }
        return ans;
    }
};