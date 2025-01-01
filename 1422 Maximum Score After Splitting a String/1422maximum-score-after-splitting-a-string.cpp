class Solution {
public:
    int maxScore(string s) {
        int l=s.length();
        int ans=0;
        for(int i=1;i<l;i++){
            int lc=0,rc=0;
           for(int j=0;j<i;j++){
            if(s[j]=='0')lc++;
           }
           for(int j=i;j<l;j++){
            if(s[j]=='1')rc++;
           }
            ans=max(ans,lc+rc);
        }
        return ans;
    }
};