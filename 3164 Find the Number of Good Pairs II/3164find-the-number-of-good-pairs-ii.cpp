class Solution {
public:
    long long numberOfPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        unordered_map<int,int>mapp;
        for(auto it : nums2)mapp[it]++;
        long long ans=0;
        for(auto it : nums1){
           if(it%k==0){
            it/=k;
            for(int i=1;i*i<=it;i++){
                if(it%i==0){
                    ans+=1ll*mapp[i];
                    if(i!=it/i)
                        ans+=1ll*mapp[it/i];
                }
            }
           }
        }
        return ans;
    }
};