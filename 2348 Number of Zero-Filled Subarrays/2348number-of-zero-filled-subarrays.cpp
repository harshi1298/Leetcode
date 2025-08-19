class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        long long ans=0;
        int l=-1,flag=0,n=nums.size();
        for(int i=0;i<n;i++){
            flag=nums[i]==0;
            if(flag){
                ans+=(i-l);
            }
            else{
                l=i;
            }
        }
        return ans;
    }
};