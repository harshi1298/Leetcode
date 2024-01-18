class Solution {
public:
    int hammingWeight(uint32_t n) {
        int l=0;
        for(int i=0;i<32;i++){
            if(n%2!=0)
             l++;
            n= n>>1;
             cout<<n<<endl;            
        }
        return l;
    }
};