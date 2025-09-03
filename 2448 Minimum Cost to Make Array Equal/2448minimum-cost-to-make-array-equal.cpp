class Solution {
private:
    long long solve(vector<int>&nums,vector<int>&cost,int mid){
        long long count=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            count+=(1ll*cost[i]*(abs(nums[i]-mid)));
        }
        return count;
    }
public:
    long long minCost(vector<int>& nums, vector<int>& cost) {
        int st = *min_element(nums.begin(), nums.end());
        int end = *max_element(nums.begin(), nums.end());
        long long ans = solve(nums, cost, st); 
        while(st<=end){
            int mid=st+(end-st)/2;
            long long x1=solve(nums,cost,mid);
            long long x2=solve(nums,cost,mid+1);
            ans=min(x1,x2);
            if(x1>x2){
              st=mid+1;
            }
            else{
               end=mid-1;
            }
        }
        return ans;
    }
};