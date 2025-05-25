class Solution {
public:
    string resultingString(string s) {
        stack<char>st;
        int n=s.length();
        for(int i=0;i<n;i++){
            if(!st.empty() && ((st.top()+1-'a')%26==s[i]-'a' || (s[i]+1-'a')%26==st.top()-'a'))st.pop();
            else st.push(s[i]);
        }
        string ans="";
        while(!st.empty()){ans.push_back(st.top());st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};