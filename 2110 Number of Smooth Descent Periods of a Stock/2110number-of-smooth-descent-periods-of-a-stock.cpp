class Solution {
public:
    long long getDescentPeriods(vector<int>& p) {
        int l=0;
        int n=p.size();
        long long ans=1;
        for(int r=1;r<n;r++){
           if(p[r-1]-p[r]==1)ans+=1ll*(r-l+1);
           else{
            ans+=1ll;
            l=r;
           }
        }
        return ans;
    }
};