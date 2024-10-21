class Solution {
public:
    int characterReplacement(string s, int k) {
       int r=0,l=0;
       int size=s.length();
       int count=0,ans=0;
       vector<int>c(26,0);
       for(;r<size;r++){
          c[s[r]-'A']++;
          count=max(count,c[s[r]-'A']);
          while((r-l+1)-count>k){
            c[s[l]-'A']--;
            l++;
          }
          ans=max(ans,r-l+1);
       }
       return ans;
    }
};