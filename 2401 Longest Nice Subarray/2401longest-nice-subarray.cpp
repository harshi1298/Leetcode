class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int l=0,r=0,m=0;
        int ans=0;
        int n=nums.size();
        for(int r=0;r<n;r++){
            while(l<r && (m & nums[r])!=0){
                m=m^nums[l];
                l++;
            }
            m=m|nums[r];
            ans=max(ans,(r-l+1));
        }
        return ans;
    }
};