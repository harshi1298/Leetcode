class Solution {
public:
    string minRemoveToMakeValid(string s) {
        stack<int>st;
        unordered_map<int,int>mapp;
        for(int i=0;i<s.length();i++){
            if(s[i]=='('){
                st.push(i);
            }
            else if(s[i]==')'){
                if(!st.empty())st.pop();
                else {
                    mapp[i]=1;
                }
            }
        }
        while(!st.empty()){
            mapp[st.top()]=1;
            st.pop();
        }
        string ans="";
        for(int i=0;i<s.length();i++){
            if(!mapp[i])ans.push_back(s[i]);
        }
        return ans;
    }
};