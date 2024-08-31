class Solution {
public:
    int generateKey(int num1, int num2, int num3) {
        int ans=0,s=1;
        while(num1 && num2 && num3){
            int k=num1%10;
            int l=num2%10;
            int m=num3%10;
            num1/=10;
            num2/=10;
            num3/=10;
            int mini=min(k,min(l,m));
            ans=mini*s+ans;
            s=s*10;
        }
        return ans;
    }
};