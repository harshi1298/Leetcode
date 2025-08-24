class Solution {
public:
    bool partitionArray(vector<int>& nums, int k) {
        int n=nums.size();
        if(n%k!=0)return 0;
        unordered_map<int,int>mapp;
        for(auto it : nums){
            mapp[it]++;
        }
        int maxi=0;
        for(auto [_,val]: mapp){
            maxi=max(maxi,val);
        }
        int group=n/k;
        return  group>=maxi;
    }
};