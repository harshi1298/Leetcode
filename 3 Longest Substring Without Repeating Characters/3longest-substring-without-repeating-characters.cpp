class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l=0,r=0;
        int ans=0;
        unordered_map<char,int> m;
        while(r<s.length()){
          if(m.find(s[r])==m.end()){
            m[s[r]]=r;
            ans=max(ans,r-l+1);
            r++;
          }
          else{
            int x=m[s[r]]+1;
            for(int i=l;i<=m[s[r]];i++)m.erase(s[i]);
            l=x;
            m[s[r]]=r;
            r++;
          }
        }
        return ans;
    }
};