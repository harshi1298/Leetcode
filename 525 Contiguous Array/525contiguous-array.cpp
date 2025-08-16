class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int,int>mapp;
        int n=nums.size(),count=0,ans=0;
        mapp[0]=-1;
        for(int i=0;i<n;i++){
            if(nums[i])count++;
            else count--;
            if(mapp.find(count)==mapp.end()){
                mapp[count]=i;
            }
            else{
                ans=max(ans,i-mapp[count]);
            }
        }
        return ans;
    }
};