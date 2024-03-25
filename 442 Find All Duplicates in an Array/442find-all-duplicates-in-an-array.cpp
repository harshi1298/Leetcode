class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int> check(100000,0);
        int l=nums.size();
        for(int i=0;i<l;i++){
            check[nums[i]-1]++;
        }
        vector<int>ans;
        for(int j=0;j<100000;j++){
            if(check[j]>1){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};