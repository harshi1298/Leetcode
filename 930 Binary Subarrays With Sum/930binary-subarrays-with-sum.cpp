class Solution {
private:
   int solve(vector<int>& nums,int goal){
    int l=0,s=nums.size();
    int sum=0,count=0;
    for(int i=0;i<s;i++){
        sum+=nums[i];
        while(l<=i && sum>goal){
           sum-=nums[l];
           l++;
        }
        count+=i-l+1;
    }
    return count;
   }
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int ans=0;
        ans=ans+solve(nums,goal)-solve(nums,goal-1);
        return ans;
    }
};
