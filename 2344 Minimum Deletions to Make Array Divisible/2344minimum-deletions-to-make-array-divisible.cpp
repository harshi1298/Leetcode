class Solution {
public:
    int minOperations(vector<int>& nums, vector<int>& numsDivide) {
        sort(nums.begin(),nums.end());
        int ans=numsDivide[0],n=numsDivide.size();
        for(int i=1;i<n;i++){
            ans=gcd(ans,numsDivide[i]);
        }
        n=nums.size();
        for(int i=0;i<n;i++){
            if(ans%nums[i]==0)return i;
        }
        return -1;
    }
};