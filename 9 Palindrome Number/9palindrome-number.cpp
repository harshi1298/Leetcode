class Solution {
public:
    bool isPalindrome(int x) {
        if(x>=0){
        int c=x;
      long long k=0;
      while(x!=0){
          k=(k*10)+x%10;
          x=x/10;
          cout<<k<<" ";
      }
      if(c==k)
         return 1;
      else
        return 0;  
    }
    else
      return 0;}
};