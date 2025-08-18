class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
       int n=s.length(),count=0, minlen=n+1;
       string ans="";
       for(int i=0;i<n;i++){
         int count=0;
         int j;
         string temp="";
         for(j=i;j<n;j++){
          temp.push_back(s[j]);
          count+=(s[j]=='1');
          if(count==k)break;
         }
         if(count==k && (j-i+1)<minlen){
            minlen=(j-i)+1;
            ans=temp;
         }
         if(count==k && (j-i+1)==minlen){
            ans=min(ans,temp);
         }
       }
       return ans;
    }
};