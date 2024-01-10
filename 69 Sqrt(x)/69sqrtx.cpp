class Solution {
public:
    int mySqrt(int x) {
        int n;
        long long k=x;
        if(x>2147483648/2){
             k=2*46340;
        }
        long long l=0;
        if(x==1)
           return 1;
       for(int i=0;l<=k;i++){
           if(((l+k)/2)*((l+k)/2)==x){
               n=(l+k)/2;
               break;
               }
            else if(((l+k)/2)*((l+k)/2)>x){
                 
                 if(((l+k)/2-1)*(((l+k)/2-1))<x){
                    n=(l+k)/2-1;
                    break;}
              k=(l+k)/2;
            }
            else if(((l+k)/2)*((l+k)/2)<x){
                
                 if(((l+k)/2+1)*(((l+k)/2+1))>x){
                    n=(l+k)/2;
                    break;}
            l=(l+k)/2;
            }
           }
           return n;
       }
    
        
    
};