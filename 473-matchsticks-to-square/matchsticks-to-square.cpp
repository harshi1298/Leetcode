class Solution {
int length=0;
vector<vector<int>>dp;
private:
    bool solve(int mask,vector<int>&arr,int count,int side){
        if(side==0){
            if(count==4)return true;
            else{
                count++;
                side=length;
            }
        }
        if(dp[mask][count]!=-1)return dp[mask][count];
        int n=arr.size();
        for(int i=0;i<n;i++){
            if((mask>>i) & 1)continue;
            int nm=mask | (1<<i);
            if(side-arr[i]>=0 && solve(nm,arr,count,side-arr[i])){
              return  dp[mask][count]=true;
            }
        }
        return  dp[mask][count]=false;
    }
public:
    bool makesquare(vector<int>& matchsticks) {
        int total=accumulate(matchsticks.begin(),matchsticks.end(),0);
        if(total %4)return false;
        length=total/4;
        int n=matchsticks.size();
        dp.resize((1<<n)+1,vector<int>(5,-1));
        return solve(0,matchsticks,1,total/4);
    }
};