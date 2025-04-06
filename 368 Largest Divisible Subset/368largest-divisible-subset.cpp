class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n=nums.size(),maxind=0;;
        sort(nums.begin(),nums.end());
        vector<int>dp(n,1);
        vector<int>temp(n,0);
        for(int i=0;i<n;i++)temp[i]=i;
        int ans1=0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[i]%nums[j]==0){
                    if(dp[i]<dp[j]+1){
                        dp[i]=dp[j]+1;
                        temp[i]=j;
                    }
                }
            }
            if(ans1<dp[i]){
                ans1=dp[i];
                maxind=i;
            }
        }
        cout<<ans1<<" ";
        vector<int>ans;
        while(maxind!=temp[maxind]){
            ans.push_back(nums[maxind]);
            maxind=temp[maxind];
        }
        ans.push_back(nums[maxind]);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};