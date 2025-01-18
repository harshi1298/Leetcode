class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>mapp;
       int sze=nums.size(),ans=0;
       int sum=0;
       mapp[0]=1;
       for(int i=0;i<sze;i++){
        sum+=nums[i];
        if(mapp.find(sum-k)!=mapp.end()){
            ans+=mapp[sum-k];
        }
        if(mapp.find(sum)!=mapp.end()){
            mapp[sum]++;
        }
        else mapp[sum]=1;
       }
       return ans;
    }
};