class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n=nums.size()-1;
        int l=n;
        if(l==0) return;
            while(n>0 && nums[n]<=nums[n-1]) {
            n--;}
            if(n==0){
                reverse(nums.begin(),nums.end());
                return;
            }
            int v=nums[n-1];
            while(v>=nums[l]){
                l--;
            }
            swap(nums[n-1],nums[l]);
            for(int i=n,j=nums.size()-1;i<j;i++,j--)
             swap(nums[i],nums[j]);
            return;
    }
};