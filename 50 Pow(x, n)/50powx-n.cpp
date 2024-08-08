class Solution {
private:
   double solve(double x, long long n){
    double ans=1.0;
    while (n) {
    if (n % 2) {
      ans = ans * x;
      n = n- 1;
    } else {
      x = x * x;
      n = n / 2;
    }
    }
    return ans;
   }
public:
    double myPow(double x, long long n) {
        if(n==0) return 1.00;
        else if(n>0) return solve(x,n);
        else{
            n=n*-1;
            return 1/solve(x,n);
        }
    }
};