class Solution {
public:
    int minFlips(int a, int b, int c) {
        int ans=0;
       while(a || b || c){
        int k=a&1;
        int l=b&1;
        int m=c&1;
        a=a>>1;
        b=b>>1;
        c=c>>1;
        if(k==0 && l==0 && m==1)ans++;
        else if(k==1 && l==1 && m==0)ans=ans+2;
        else if((k==1 || l==1)&& m==0)ans++;
       }
       return ans;
    }
};