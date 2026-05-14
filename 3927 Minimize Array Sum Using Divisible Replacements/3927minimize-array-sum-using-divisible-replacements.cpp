class Solution {
public:
    long long minArraySum(vector<int>& nums) {
        vector<int>arr(1e5+1,0);
        for(int i=1;i<=1e5;i++)arr[i]=i;
        set<int>st(nums.begin(),nums.end());
        long long ans=0;
        for(auto &it :  st){
            if(arr[it]==it){
                for(int j=it;j<=1e5;j+=it){
                    arr[j]=min(arr[j],it);
                }
            }
        }
        for(auto it : nums)ans+=arr[it];
        return ans;
    }
};