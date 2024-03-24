class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        vector<int> check(100000,0);
        int l=nums.size();
        for(int i=0;i<l;i++){
            check[nums[i]-1]++;
        }
        for(int j=0;j<100000;j++){
            if(check[j]>1){
                return j+1;
                break;
            }
        }
        return 0;
    }
};