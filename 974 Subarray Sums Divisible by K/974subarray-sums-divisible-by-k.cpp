class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n=nums.size();
        unordered_map<int,int>mapp;
        mapp[0] = 1;
        int sum=0,ans=0;
        for(int i=0;i<n;i++){
            sum += nums[i];
           int modulo=(sum%k+k)%k;
           ans+=mapp[modulo];
           mapp[modulo]++;
        }
        return ans;
    }
};