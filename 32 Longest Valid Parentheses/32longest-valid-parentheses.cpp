class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int>st;
        st.push(-1);
        int n=s.length(),ans=0;
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else {
                if(st.top()==-1){
                    st.push(i);
                }
                else if(s[st.top()]=='('){
                    st.pop();
                    ans=max(ans,i-st.top());
                }
                else{
                    st.push(i);
                }
            }
        }
        return ans;
    }
};