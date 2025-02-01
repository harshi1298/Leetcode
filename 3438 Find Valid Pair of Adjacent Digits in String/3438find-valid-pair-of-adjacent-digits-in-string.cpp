class Solution {
public:
    string findValidPair(string s) {
        vector<int>tmp(11,0);
        for(int i=0;i<s.length();i++){
            tmp[s[i]-'0']++;
        }
       string ans="";
        // cout<<tmp[0];
       for(int i=1;i<s.length();i++){
           if(s[i]!=s[i-1]){
               if((tmp[s[i]-'0']==(s[i]-'0')) && (tmp[s[i-1]-'0']==(s[i-1]-'0'))){
                   ans+=s[i-1];
                   ans+=s[i];
                   return ans;
               }
           }
       }
        return "";
    }
};