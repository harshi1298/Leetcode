class Solution {
public:
    int nonSpecialCount(int l, int r) {
      int st=sqrt(r);
      int n=st*st==r?st:st+1;
      vector<int>isprime(n+1,1);
      isprime[0]=isprime[1]=0;
      for(int i=2;i*i<=n;i++){
        if(isprime[i]){
            for(int j=i*i;j<=n;j+=i){
               isprime[j]=0;
            }
        }
      }
      int count=0;
      st=sqrt(l);
      int j=st*st==l?st:st+1;
      for(int i=j;i<=n;i++){
        if (isprime[i]) {
             long long sq = 1LL * i * i;
                if (sq >= l && sq <= r)
                    ++count;
            }
      }
      return r-l+1-count;
    }
};