class Solution {
public:
    string stringHash(string s, int k) {
        string ans="";
       for(int i=0;i<s.length();){
           int j=0;
           int n=0;
           while(j<k){
            n=n+(s[i]-'a');
            n=n%26;
            i++;
            j++;
           }
           ans=ans+(char)(n+'a');
       }
       return ans;
    }
};