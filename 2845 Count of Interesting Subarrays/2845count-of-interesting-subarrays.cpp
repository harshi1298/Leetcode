class Solution {
public:
    long long countInterestingSubarrays(vector<int>& nums, int modulo, int k) {
        int n=nums.size();
        vector<int>count(n+1);
        for(int i=1;i<=n;i++){
            count[i]=count[i-1]+(nums[i-1]%modulo==k);
        }
        unordered_map<int,int>mapp;
        long long ans=0;
         mapp[0] = 1;
        for(int i=1;i<=n;i++){
           ans+=(mapp[(count[i]+modulo-k)%modulo]);
           mapp[count[i]%modulo]++;
        }
        return ans;
    }
};