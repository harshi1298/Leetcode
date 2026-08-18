class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int,long long>mapp;
        long long l=0;
        long long count=0,n=nums.size();
        long long exc=0;
        for(int r=0;r<n;r++){
           count+=mapp[nums[r]];
           mapp[nums[r]]++;
           while(count>=k){
            mapp[nums[l]]--;
            count-=mapp[nums[l]];
            l++;
           }
           exc+=(r-l+1);

        }
        return 1ll*n*(n+1)/2-exc;
    }
};