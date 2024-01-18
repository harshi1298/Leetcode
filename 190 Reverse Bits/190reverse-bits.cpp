class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        int ans=0;
        int i=0;
        while(i<32){
            ans<<=1;
            ans=ans^(n&1);
        n>>=1;
        i++;}
        return ans;
    }
};