class Solution {
public:
    bool isPowerOfThree(int n) {
        if(n==1)return true;
        while(n>0 && n%3==0){
            if(n==1)return true;
            n/=3;
            if(n==1)return true;
        }
        return false;
    }
};