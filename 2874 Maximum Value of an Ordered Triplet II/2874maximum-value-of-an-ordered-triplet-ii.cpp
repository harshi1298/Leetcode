class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long maxi=0,max_dif=0,ans=0;
        for(int i=2;i<nums.size();i++){
            maxi=max(maxi,(long long)nums[i-2]);
            max_dif=max(max_dif,maxi-nums[i-1]);
            ans=max(ans,max_dif*nums[i]);   
        }
        return ans;
    }
};