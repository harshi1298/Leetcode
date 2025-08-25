class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>pre(n),suff(n);
        pre[0]=h[0],suff[n-1]=h[n-1];
        for(int i=1;i<n;i++)pre[i]=max(pre[i-1],h[i]);
        for(int i=n-2;i>=0;i--)suff[i]=max(suff[i+1],h[i]);
        int ans=0;
        for(int i=0;i<n;i++){
            int lm=i>0?pre[i-1]:0;
            int rm=i<n-1?suff[i+1]:0;
            ans+=max(0,(min(lm,rm)-h[i]));
        }
        return ans;
    }
};