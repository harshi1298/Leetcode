class Solution {
public:
    int longestContinuousSubstring(string s) {
        int l=0,ans=0;
        int n=s.length();
        for(int r=0;r<n;r++){
            if((r-l)==(s[r]-s[l]))ans=max(ans,r-l+1);
            else l=r;
        }
        return ans;
    }
};