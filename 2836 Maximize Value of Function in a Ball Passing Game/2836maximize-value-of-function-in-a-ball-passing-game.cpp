class Solution {
public:
    long long getMaxFunctionValue(vector<int>& r, long long k) {
        long long n=r.size();
        long long row=log2(1e10)+1;
        vector<vector<long long>>sum(row,vector<long long>(n,0));
        vector<vector<long long>>par(row,vector<long long>(n,0));
        for(long long i=0;i<n;i++){
            par[0][i]=r[i];
            sum[0][i]=r[i];
        }
        for(long long i=1;i<row;i++){
            for(long long j=0;j<n;j++){
                long long p=par[i-1][j];
                par[i][j]=par[i-1][p];
                sum[i][j]=sum[i-1][j]+sum[i-1][p];
            }
        }
        long long ans=0;
        for(long long i=0;i<n;i++){
            long long cur=i,node=i;
            for(long long j=0;j<row;j++){
                if((k>>j) & 1){
                    cur+=sum[j][node];
                    node=par[j][node];
                }
            }
            ans=max(ans,cur);
        }
        return ans;
    }
};