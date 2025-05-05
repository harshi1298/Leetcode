class Solution {
    int modulo=1e9+7;

public:
    int numTilings(int n){
        long long t1=1,t2=2,t3=5;
        long long ans=0;
        if(n==1)return t1;
        if(n==2)return t2;
        if(n==3)return t3;
        for(int i=4;i<=n;i++){
            ans=2*t3+t1;
            t1=t2;
            t2=t3;
            t3=ans;
            ans=ans%modulo;
            t1%=modulo;
            t2%=modulo;
            t3%=modulo;
        }
        return ans;
    } 
};