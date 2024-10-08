class Solution {
public:
    int minSwaps(string s) {
        stack<char>st;
        int ans=0;
        for(int i=0;i<s.length();i++){
            if(s[i]==']'){
                if(!st.empty()){
                    st.pop();
                }
                else {
                    st.push('[');
                    ans++;
                }
            }
            else{
                st.push('[');
            }
        }
        return ans;
    }
};