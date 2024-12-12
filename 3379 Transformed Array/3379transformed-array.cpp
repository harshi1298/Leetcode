class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int size=nums.size();
        vector<int>result(size);
        for(int i=0;i<size;i++){
            if(!nums[i])result[i]=nums[i];
            else{
                int k=(i+nums[i])%size;
                k=k<0?k+size:k;
                result[i]=nums[k];
            }
        }
        return result;
    }
};