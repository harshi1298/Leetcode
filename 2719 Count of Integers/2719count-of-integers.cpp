class Solution {
private: 
    int mod=1e9+7;
    int dp[24][2][22*9+1];
    int solve(string &str,int idx,int tight,int sum,int maxsum,int minsum){
        if(idx==str.length()){
            if(sum>=minsum && sum<=maxsum)return 1;
            else return 0;
        }
        if(dp[idx][tight][sum]!=-1)return dp[idx][tight][sum];
        int limit=tight==1?str[idx]-'0':9;
        long long ans=0;
        for(int i=0;i<=limit;i++){
            int newt=tight && (i==str[idx]-'0');
            ans+=solve(str,idx+1,newt,sum+i,maxsum,minsum);
            ans%=mod;
        }
        return dp[idx][tight][sum]=(int)ans;
    }
public:
    int count(string num1, string num2, int min_sum, int max_sum) {
        int sum=0;
        for(int i=0;i<num1.length();i++){
            sum+=(num1[i]-'0');
        }
        if(sum>=min_sum && sum<=max_sum)sum=1;
        else sum=0;
        memset(dp,-1,sizeof(dp));
        int right= solve(num2,0,1,0,max_sum,min_sum);
        memset(dp,-1,sizeof(dp));
        int left=solve(num1,0,1,0,max_sum,min_sum);
        return (right-left+mod)%mod+sum;
    }
};