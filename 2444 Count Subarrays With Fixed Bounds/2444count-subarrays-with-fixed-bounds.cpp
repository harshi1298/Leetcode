class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        long long ans=0;
        int n=nums.size();
        int minindex=-1;
        int maxindex=-1,invalid=-1;;
        for(int i=0;i<n;i++){
           if(nums[i]==maxK){
            maxindex=i;
           }
           if(nums[i]==minK){
            minindex=i;
           }
           if(nums[i]>maxK || nums[i]<minK){
            maxindex=-1;minindex=-1;
            invalid=i;
           }
           if(maxindex!=-1 && minindex!=-1){
            ans += max(0, min(minindex, maxindex) - invalid);
           }
        }
        return ans;
    }
};