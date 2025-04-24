class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums) {
        set<int>unique(nums.begin(), nums.end());
        int k=unique.size()-1;
        int l=0,ans=0;
        unordered_map<int,int>mapp;
        for(int r=0;r<nums.size();r++){
             mapp[nums[r]]++;
             while(mapp.size()>k){
                mapp[nums[l]]--;
                if(mapp[nums[l]]==0)mapp.erase(nums[l]);
                l++;
             }
             ans+=(r-l+1);
        }
        return nums.size()*(nums.size()+1)/2-ans;
    }
};