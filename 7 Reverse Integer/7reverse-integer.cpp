class Solution {
public:
    int reverse(int x) {
     int k=0 ;
     for(int i=0;x!=0;i++){
         if(((k)<=INT_MAX/10)&&((k)>=INT_MIN/10)){
         k=(k*10)+x%10;
         x=x/10;}
         else
          return 0;
     
     }
     return k;
    }
};
