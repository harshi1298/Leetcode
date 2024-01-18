class Solution {
public:
    int divide(int x, int y) {
        long long k=0;
        if(x==0)
         return 0;
         else if(x==y)
          return 1;
          else if(y==1&&x!=INT_MIN)
          return x;
        else if(y==-1&&x!=INT_MIN)
        return -1*x;
        else{
        if(x==INT_MIN||y==INT_MIN){
            if(y==1)
            return INT_MIN;
            if(y==-1)
            return (INT_MAX);
            if(x<0&&y>0){
            while(x<=0)
             { x=x+y;
              k++;}
              k=-1*(k-1);
            }
            else if(x>0&&y<0)
             k=0;
            else
            {
                if(x==INT_MIN&&y==INT_MIN)
                return 1;
                else if(x==INT_MIN){
                    while(x<=0){
                        x=x+(-1*y);
                        k++;
                    }
                    k--;
                    return k;
                }
                else
                return 0;
            }
        }
        else
       { if((x<0||y<0)&&!(x<0&&y<0)){
            if(x<0)
            x=-1*x;
            if(y<0)
            y=-1*y;
            while(x>=0){
                x=x-y;
                k++;
            }
            cout<<"jhhuhj";
            k=-1*(k-1);
        }
        else{
            if(x<=0)
            x=-1*x;
            if(y<0)
            y=-1*y;
            while(x>=0){
                x=x-y;
                k++;
            }
            k--;
        }}}
         return k;
        }
};