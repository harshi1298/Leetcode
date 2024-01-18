class Solution {
public:
    int ret(uint32_t n) {
        int count = 0;
        while(n != 0){
            if(n&1){//checks if last bit = 1
                count++;
            }
            n >>= 1;//right shifts by 1
        }
        return count;
    }
    vector<int> countBits(int n) {
        vector<int> ans(n+1,0);
        for(int i=0;i<=n;i++){
            ans[i]=ret(i);
        }
        return ans;
    }
};