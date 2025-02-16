class Solution {
public:
    int beautySum(string s) {
      int ans=0;
      for(int i=0;i<s.length();i++){
         vector<int>pre(26,0);
         int mini=INT_MAX,maxi=INT_MIN;
        for(int j=i;j<s.length();j++){
            pre[s[j]-'a']++;
             mini=INT_MAX,maxi=INT_MIN;
            for(int k=0;k<26;k++){
               if(pre[k]!=0){
                mini=min(mini,pre[k]);
                maxi=max(maxi,pre[k]);
               }
            }
            ans+=(maxi-mini);
        }
      }
      return ans;
    }
};