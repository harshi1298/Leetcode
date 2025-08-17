class Solution {
public:
    int maximum69Number (int num) {
        string t=to_string(num);
        string ans=t;
        for(int i=0;i<t.length();i++){
            string s=t;
            s[i]=s[i]=='6'?'9':'6';
            ans=max(ans,s);
        }
        return stoi(ans);
    }
};