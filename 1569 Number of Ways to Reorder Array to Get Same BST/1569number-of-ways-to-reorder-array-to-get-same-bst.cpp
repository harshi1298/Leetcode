class Solution {
private:
    vector<vector<long long>>pascal;
    int mod=1e9+7;
    long long solve(vector<int>&nums){
        int n=nums.size();
        if(n<=2)return 1;
        int root=nums[0];
        vector<int>left,right;
        for(int i=1;i<n;i++){
            if(nums[i]<root)left.push_back(nums[i]);
            else right.push_back(nums[i]);
        }
        return ((solve(left)*solve(right))%mod *pascal[n-1][left.size()])%mod;
    }
public:
    int numOfWays(vector<int>& nums) {
        int n=nums.size();
        pascal.resize(n+1);
        for(int i=0;i<=n;i++){
            pascal[i]=vector<long long>(i+1,1);
            for(int j=1;j<i;j++){
               pascal[i][j]=(pascal[i-1][j-1]+pascal[i-1][j])%mod;
            }
        }
        return (solve(nums)-1+mod)%mod;
    }
};