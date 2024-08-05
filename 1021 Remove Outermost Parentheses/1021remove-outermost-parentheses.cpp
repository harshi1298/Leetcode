class Solution {
public:
    string removeOuterParentheses(string s) {
        int l=0;
        string ans="";
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='(') {
             if(count!=0) ans=ans+s[i];
             count++;
            }
            if(s[i]==')'){
                 count--;
                 if(count!=0) ans=ans+s[i];
            }
        }
        return ans;
    }
};