#define pr pair<int,int>
class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
       int n=scores.size();
       vector<pr>temp;
       for(int i=0;i<n;i++){
        temp.push_back(make_pair(ages[i],scores[i]));
       }
       sort(temp.begin(),temp.end());
       vector<int>dp(n+1,0);
       int ans=temp[0].second;
       for(int i=0;i<n;i++)dp[i]=temp[i].second;
       for(int i=1;i<n;i++){
        for(int j=0;j<i;j++){
            int s1=temp[i].second;
            int s2=temp[j].second;
            if(s2<=s1){
                dp[i]=max(dp[i],dp[j]+s1);
            }
            ans=max(ans,dp[i]);
        }
       }
       return ans;
    }
};