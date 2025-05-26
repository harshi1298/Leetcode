class Solution {
private:
    bool isprime(long long n){
        if(n<2)return false;
        for(long long i=2;i*i<=n;i++){
            if(n%i==0)return false;
        }
        return true;
    }
public:
    long long sumOfLargestPrimes(string s) {
        set<long long>st;
        long long n=s.length();
        for(long long i=0;i<n;i++){
            string str="";
            for(long long j=i;j<n;j++){
                str+=s[j];
                long long temp=stoll(str);
                if(isprime(temp)){
                    st.insert(temp);
                }
            }
        }
        long long sum=0;
        long long i=0;
        for(auto it=st.rbegin();it!=st.rend() && i<3;i++,it++){
            sum+=*it;
        }
        return sum;
    }
};