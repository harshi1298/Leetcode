class Solution {
public:
    int minLength(string s) {
        stack<char>st;
        for(int i=0;i<s.length();i++){
            if(!st.empty() && st.top()=='A'){
                if(s[i]!='B')st.push(s[i]);
                else st.pop();
            }
            else  if(!st.empty() && st.top()=='C'){
                if(s[i]!='D')st.push(s[i]);
                else st.pop();
            }
            else {
                st.push(s[i]);
            }
        }
        return st.size();
    }
};