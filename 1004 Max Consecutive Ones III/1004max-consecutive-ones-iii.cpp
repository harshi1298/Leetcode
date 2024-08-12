class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int l=0;int r=0,ans=0,m=k;
        int j=nums.size()-1;
        while(r<=j){
            if(k||nums[r]){
                if(!nums[r])k--;
                ans=max(ans,r-l+1);
                r++;
            }
            else{
            while(nums[l])l++;
            l++;
            k++; 
            }
        }
        return ans;
    }
};