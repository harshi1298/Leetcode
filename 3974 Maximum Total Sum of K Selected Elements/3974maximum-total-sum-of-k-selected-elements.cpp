class Solution {
public:
    long long maxSum(vector<int>& nums, int k, int mul) {
        sort(nums.begin(),nums.end(),greater<long long>());
        long long ans=0;
        for(int i=0;i<min(k,(int)nums.size());i++){
            if(mul>0){
                ans+=1ll*(1ll*nums[i]*1ll*mul);
                mul--;
            }
            else ans+=1ll*nums[i];
        }
        return ans;
    }
};