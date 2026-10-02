class Solution {
public:
    int maxEqualAdjacentPairs(vector<int>& nums) {
        map<pair<int,int>,int>mapp;
        int ans=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]==nums[i-1]){
                ans++;
            }
            else{
                int mini=min(nums[i],nums[i-1]);
                int maxi=max(nums[i],nums[i-1]);
                mapp[{mini,maxi}]++;
            }
        }
        int maxi=0;
        for(auto [k,v]: mapp)maxi=max(maxi,v);
        return ans+maxi;
    }
};