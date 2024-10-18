class Solution {
public:
    string decodeString(string s) {
        string ans="";
        int i=0;
        while(s[i]>='a'  && s[i]<='z')ans=ans+s[i++];
        stack<string>st;
        for(;i<s.length();){
            if(s[i]=='['){
                st.push("[");
                i++;
            }
            else if(s[i]-'0'>=0  && s[i]-'0'<=9){
                string num="";
                while(i<s.length() && s[i]-'0'>=0  && s[i]-'0'<=9){
                   num=num+s[i++];
                }
                st.push(num);
            }
            else if(s[i]==']'){
               string k=st.top();
               st.pop();
               st.pop();
               int l=stoi(st.top());
               st.pop();
               string temp="";
               for(int i=0;i<l;i++){
                  temp+=k;
               } 
               while(!st.empty() && st.top()!="["){
                  temp=st.top()+temp;
                  st.pop();
               }
               st.push(temp);
               i++;
            }
            else{
                string temp="";
                if( !st.empty() && st.top()[0]>='a' && st.top()[0]<='z'){
                  temp=st.top()+temp;
                  st.pop();
                  }
                while(i<s.length() && s[i]>='a' && s[i]<='z'){
                    temp+=s[i++];
                }
                st.push(temp);
            }
        }
        string tans="";
        while(!st.empty()){
            tans=st.top()+tans;
            st.pop();
        }
        return ans+tans;
    }
};