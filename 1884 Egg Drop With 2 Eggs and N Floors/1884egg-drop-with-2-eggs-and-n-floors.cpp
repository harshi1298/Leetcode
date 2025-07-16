class Solution {
public:
    int twoEggDrop(int n) {
        double t=(-1+sqrt(1+8*n))/2;
       return t==(int(t))?t:int(t+1);
    }
};