class Solution {
private:
    vector<vector<int>>dp;
    int solve(int curr,int day,int k,vector<vector<int>>& st, vector<vector<int>>& tr,int n){
        if(day>=k)return 0;
        if(dp[curr][day]!=-1)return dp[curr][day];
        int ans=0;
        for(int i=0;i<n;i++){
            if(i==curr)continue;
            ans=max(ans,solve(i,day+1,k,st,tr,n)+tr[curr][i]);
        }
        
        ans=max(ans,solve(curr,day+1,k,st,tr,n)+st[day][curr]);
        return dp[curr][day]=ans;
    }
public:
    int maxScore(int n, int k, vector<vector<int>>& stayScore, vector<vector<int>>& travelScore) {
        // int ans=0;
        
        // for(int i=0;i<n;i++){
        //     dp.assign(n+1,vector<int>(k+1,-1));
        //     ans=max(ans,solve(i,0,k,stayScore,travelScore,n));
        // }
        // return ans;
        vector<int> dp(n,0);
        for(int i=0;i<k;i++){
            vector<int> newdp(n,0);
            for(int j=0;j<n;j++){
                int maxi=0;
                for(int nx=0;nx<n;nx++){
                    maxi=max(maxi,dp[nx]+(j==nx?stayScore[i][j]:travelScore[nx][j]));
                }
                newdp[j]=maxi;
            }
            dp=newdp;
        }
        return *max_element(dp.begin(),dp.end());
    }
};