class Solution {
    long long modulo=(1e9)+7; 
private:
   int pow(long long  a,long long b){
   long long ans = 1.0;
  long long nn = b;
  while (nn) {
    if (nn % 2) {
      ans = ans * a;
      ans=ans%modulo;
      nn = nn - 1;
    } else {
      a = a * a;
      a=a%modulo;
      nn = nn / 2;
    }
  }
  return ans;
   }
public:
    int countGoodNumbers(long long  n) {
      long long k=pow(5,n/2);
        if(n%2!=0) k=(k*5)%modulo;
       long long l=pow(4,n/2);
        long long ans=(l*k)%modulo;
        return ans;
    }
};