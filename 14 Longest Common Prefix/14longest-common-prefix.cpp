class Solution {
public:
        int min(int a,int b){
            if(a>b)
              return b;
            else
             return a;
        }
    string longestCommonPrefix(vector<string>& s){
        int l=1;
        int j;
        string str;
        for(int i=0;i<s[0].length() && l;i++){
            for(j=0;j<s.size()-1 && l;j++){
                if(s[j][i]!=s[j+1][i] || min(s[j].length(),s[j+1].length())==i+1){
                    if(s[j][i]==s[j+1][i] && min(s[j].length(),s[j+1].length())==i+1){
                        l=1;
                    }
                    else
                   l=0;
                   cout<<l;}
                }
            if(l==1)
             str+=s[0][i];
        }
        return str;
    }
};