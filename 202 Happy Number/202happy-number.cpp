class Solution {
public:
    int check(int n){
        if(n>=0&&n<10){
            if(n==1||n==7)
             return 1;
            else
             return 0;}
             int k=0;
             while(n!=0){
               k=k+((n%10)*(n%10));
               n=n/10;
        }
       return check(k);
    }
    bool isHappy(int n) {
        int s=check(n);
        return s;
    }
};