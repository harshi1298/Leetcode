class Solution {
bool solve(int m,int n,int k,int mid){
    int count=0;
    for(int i=1;i<=m;i++){
        count+=mid/i<=n?mid/i:n;
    }
    return count>=k;
}
public:
    int findKthNumber(int m, int n, int k) {
        int ans=m*n;
        int st=1,end=m*n;
        while(st<=end){
            int mid=st+(end-st)/2;
            if(solve(m,n,k,mid)){
                ans=mid;
                end=mid-1;
            }
            else st=mid+1;
        }
        return ans;
    }
};