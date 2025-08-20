class Solution {
public:
    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int>dp(days[n-1]+1,1e5);
        unordered_set<int>st;
        for(auto it : days)st.insert(it);
        dp[0]=0;
        for(int i=1;i<=days[n-1];i++){
            if(st.find(i)==st.end())dp[i]=min(dp[i],dp[i-1]);
            dp[i]=min(dp[i],dp[i-1]+costs[0]);
            for(int j=i;j<i+7 &&  j<=days[n-1];j++){
                dp[j]=min(dp[j],dp[i-1]+costs[1]);
            }
            for(int j=i;j<i+30 && j<=days[n-1];j++){
                dp[j]=min(dp[j],dp[i-1]+costs[2]);
            }
        }
        for(auto it : dp)cout<<it<<" ";
        return dp[days[n-1]];
    }
};