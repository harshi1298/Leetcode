class Solution {
public:
    int minBitFlips(int start, int goal) {
        int ans=0;
        while(start!=0 || goal!=0){
            int k=start&1;
            int l=goal&1;
            if(k!=l)ans++;
            start=start>>1;
            goal=goal>>1;
        }
        return ans;
    }
};