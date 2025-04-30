class Solution {
public:
    int findNumbers(vector<int>& nums) {
        int ans=0,n=nums.size();
        for(int i=0;i<n;i++){
            ans+=(to_string(nums[i]).length()%2==0);
        }
        return ans;
    }
};