class Solution {
public:
   string answerString(string word, int n) {
       int l=word.length();
       if(n==1)return word;
       string ans="";
       for(int i=0;i<l;i++){
         ans=max(ans,word.substr(i,l-n+1));
       }
       return ans;
    }
};