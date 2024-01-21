class Solution {
public:
    bool judgeSquareSum(int c) {
        long long i=0;
        int l=0;
        long long j=pow(c,0.5);
        cout<<j;
        while(i<=j){
           if((i*i+j*j)<c)
               i++;
            else if((i*i+j*j)>c)
               j--;
            else
            {
                l=1;
                break;
            }
            
        }
       return l;
    }
};