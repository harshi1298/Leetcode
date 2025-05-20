class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int n=nums.size();
        vector<int>temp(n+2);
        for (auto &q : queries) {
            temp[q[0]]++;
            temp[q[1]+1]--;
        }
        for(int i=1;i<n;i++){
            temp[i]+=temp[i-1];
        }
        for(int i=0;i<n;i++){
            if(nums[i]-temp[i]>0)return false;
        }
        return true;
    }
};