class Solution {
public:
    int rotatedDigits(int n) {
        int s=0;
        for(int a=1;a<=n;a++){
            int i=a;
         int k=0;
        int l=1;
            while(i!=0){
                if(i%10==2)
                 k=k+5*l;
                else if(i%10==5)
                k=k+2*l;
                else if(i%10==6)
                k=k+9*l;
                else if(i%10==9)
                k=k+6*l;
                else if(i%10==0||i%10==1||i%10==8)
                k=k+(i%10)*l;
                else
                 break;
                i=i/10;
                l=l*10;
            }
            if(k!=a&&i==0)
             s++;
        }
        return s;
    }
};