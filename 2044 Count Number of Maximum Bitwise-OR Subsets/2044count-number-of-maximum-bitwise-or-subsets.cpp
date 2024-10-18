class Solution {
private:
   int ans=0;
   void solve(vector<int> &nums,int maxor,int i,int val){
     if(i==nums.size()){
        if(val==maxor)ans++;
        return;
     }
     solve(nums,maxor,i+1,val);
     solve(nums,maxor,i+1,(val|nums[i]));
   }
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxor=0;
        for(auto i :nums){
            maxor=maxor|i;
        }
        solve(nums,maxor,0,0);
        return ans;
    }
};