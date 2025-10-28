class Solution {
public:
    int minOperations(int k) {
        int ans=k;
        if(k==1)return 0;
        for(int i=1;i<=k;i++){
            ans=min(ans,i+(k%(i+1)==0?k/(i+1)-1:k/(i+1)));
        }
        return ans;
    }
};