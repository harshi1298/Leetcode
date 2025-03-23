class Solution {
public:
    int maxContainers(int n, int w, int maxWeight) {
        int k=maxWeight/w;
        if(k>n*n)return n*n;
        else return k;
    }
};