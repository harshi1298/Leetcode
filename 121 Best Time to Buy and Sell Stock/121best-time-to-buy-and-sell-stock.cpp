class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size()==0) return 0; 
         int ans=0,n=prices.size(),maxi=prices[n-1];
         for(int i=n-2;i>=0;i--){
             ans=max(ans,maxi-prices[i]);
             maxi=max(maxi,prices[i]);
         }
        return ans;
    }
};