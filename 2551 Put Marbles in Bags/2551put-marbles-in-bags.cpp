class Solution {
public:
    long long putMarbles(vector<int>& weights, int k) {
        long long maxi=0,mini=0;
        int n=weights.size();
        vector<long long>sum(n-1);
        for(int i=1;i<n;i++){
            sum[i-1]=weights[i]+weights[i-1];
        }
        sort(sum.begin(),sum.end());
        if(n-k>=1)mini=accumulate(sum.begin(),sum.begin()+k-1,0LL);
        if(n-k>=1)maxi=accumulate(sum.end()-k+1,sum.end(),0LL);
        return maxi-mini;
    }
};