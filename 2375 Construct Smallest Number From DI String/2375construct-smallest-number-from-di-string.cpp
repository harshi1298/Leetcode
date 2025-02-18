class Solution {
public:
    string smallestNumber(string p) {
        int l=p.length();
        int count=0;
        string ans="";
        char temp='1';
        for(int i=0;i<l+1;i++){
            ans=ans+(char)(temp+i);
        }
      vector<int>pre(l);
      for(int i=l-1;i>=0;i--){
        if(p[i]=='I'){
           pre[i]=count;
           count=0;
        }
        else count++;
      }
      if(count!=0){
        reverse(ans.begin(),ans.begin()+count+1);
      }
      cout<<ans;
      for(int i=0;i<l;){
        if(pre[i]!=0){
           reverse(ans.begin()+i+1,ans.begin()+2+pre[i]+i);
           i=i+pre[i]; 
        }
        else i++;
      }
      return ans;
    }
};