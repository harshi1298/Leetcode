class Solution {
public:
    int fib(int n) {
        int a=1;
        int b=0;
        int sum=0;
        int i=0;
        while(i<n){
            sum=a+b;
            a=b;
            b=sum;
            i++;
        }
        return sum;
    }
};