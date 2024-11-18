class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int size=code.size();
        vector<int>ans(size,0);
        if(k>0){
            for(int i=0;i<size;i++){
                int sum=0;
                for(int j=1;j<=k;j++){
                   sum=sum+code[(i+j)%size];
                }
                ans[i]=sum;
            }
        }
        else if(k<0){
            for(int i=2*size-1;i>=size;i--){
                int sum=0;
                for(int j=k;j<0;j++){
                   sum=sum+code[(i+j)%size];
                }
                ans[i%size]=sum;
            }
        }
        return ans;
    }
};