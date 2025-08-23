class Solution {
public:
    int countMatchingSubarrays(vector<int>& nums, vector<int>& pattern) {
        int n=nums.size(),m=pattern.size(),ans=0;
        for(int i=0;i<n;i++){
            int flag=1;
            for(int k=0;k<m && flag;k++){
                if(i+k+1<n && i+k<n){
                    if(pattern[k]==1 && nums[i+k+1]<=nums[i+k]){
                       flag=0;
                    }
                    else if(pattern[k]==0 && nums[i+k+1]!=nums[i+k]){
                        flag=0;
                    }
                    else if(pattern[k]==-1 && nums[i+k+1]>=nums[i+k]){
                        flag=0;
                    }
                }
                else flag=0;
            }
            ans+=flag;
        }
        return ans;
    }
};