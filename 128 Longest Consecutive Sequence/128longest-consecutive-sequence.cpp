class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int>mapp;
        for(auto i:nums){
            mapp[i]=1;
        }  
        int ans=0;
        int count=0;
        for(int i=0.;i<nums.size() && !mapp.empty();i++){
            int j=0;
            int k=nums[i];
            while(1){
             if(mapp.find(k+j)!=mapp.end()){
                count++;
                mapp.erase(nums[i]+j);
                j++;
             }
             else break;
            }
            j=1;
            while(1){
             if(mapp.find(k-j)!=mapp.end()){
                count++;
                mapp.erase(nums[i]-j);
                j++;
             }
             else break;
            }
            ans=max(ans,count);
            count=0;
        }
        return ans;                         
    }
};