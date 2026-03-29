class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums) {
        map<int,int>mapp;
        int n=nums.size(),ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(nums[i]==1){
                if(mapp.find(2)!=mapp.end())ans=min(ans,i-mapp[2]);
            }
            if(nums[i]==2){
                if(mapp.find(1)!=mapp.end())ans=min(ans,i-mapp[1]);
            }
            mapp[nums[i]]=i;
        }
        return ans==INT_MAX?-1:ans;
    }
};