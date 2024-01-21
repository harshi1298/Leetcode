class Solution {
public:
    bool isPerfectSquare(int num) {
        int i=0;
        int j=46340;
        if(num<j)
            j=num;
        while(i<=j){
            int mid=i+(j-i)/2;
            if(mid*mid<num){
                i=mid+1;
            }
            else if (mid*mid==num){
                return true;
            }
            else
                j=mid-1;
        }
        return false;
    }
};