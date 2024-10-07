class Solution {
public:
    string reversePrefix(string word, char ch) {
        stack<char>st;
        int i;
        string ans="";
        for(i=0;i<word.length();i++){
            if(word[i]==ch){ans=ans+ch;
              while(!st.empty()){
                ans=ans+st.top();
                st.pop();
              }
            i++;
            break;
            }
            else{
                st.push(word[i]);
            }
        }
        if(!st.empty())return word;
        while(i<word.length()){
            ans=ans+word[i];
            i++;
        }
        return ans;
    }
};