class Solution {
private:
   string solve(int n){
    if(n==0)return "0";
    else{
        string s=solve(n-1);
        string temp=s;
        for(int i=0,j=s.length()-1;i<=j;i++,j--){
            if(i!=j){
            if(s[i]=='0')s[i]='1';
            else s[i]='0';
            if(s[j]=='0')s[j]='1';
            else s[j]='0';
            }
            else{
               if(s[i]=='0')s[i]='1';
               else s[i]='0'; 
            }
            swap(s[i],s[j]);
        }
        return temp+'1'+s;
    }
   }
public:
    char findKthBit(int n, int k) {
       string ans=solve(n-1);
       return ans[k-1];
    }
};