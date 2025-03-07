class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> vec(right+1,1);
        vec[0]=vec[1]=0;
        for(int i=2;i<right;i++){
            if(vec[i]){
                int j=2;
                while(i*j<=right){
                    vec[i*j]=0;
                    j++;
                }
            }
        }
        int ans=INT_MAX,prev=-1;
        vector<int> ans_t={-1,-1};
        for(int i=left;i<=right;i++){
            if(!vec[i]) continue;
            if(prev!=-1){
                if(i-prev<ans){
                    ans=i-prev;
                    ans_t={prev,i};
                }
                if(ans==1) return ans_t;
            }
            prev=i;
        }
        return ans_t;
    }
};