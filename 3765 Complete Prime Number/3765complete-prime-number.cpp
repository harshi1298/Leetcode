class Solution {
private:
    bool isprime(int n){
        if(n<2)return false;
        for(int i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
public:
    bool completePrime(int num) {
        int pre=0;
        long long l=1;
        bool ans=true;
        int k=num;
        while(num>0){
            pre+=num%10*l;
            ans=(ans&isprime(pre));
            num/=10;
            // cout<<pre<<endl;
            l*=1ll*10;
        }
        l/=10;
        num=k;
        while(l>=1){
            ans=(ans&isprime(num/l));
            // cout<<num/l<<endl;
            l/=10;
        }
        return ans;
    }
};