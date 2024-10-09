class Solution {
public:
    int minAddToMakeValid(string s) {
        int ans=0;
        int count=0;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
               count++;
            }
            if(count>0 && s[i]==')')count--;
            else if(count==0 && s[i]==')'){
                ans++;
            }
        }
        return ans+count;
    }
};