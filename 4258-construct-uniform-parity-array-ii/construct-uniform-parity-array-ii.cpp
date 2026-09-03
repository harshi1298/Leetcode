class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int mini=*min_element(nums1.begin(),nums1.end());
        if(mini%2)return true;
        int oddc=0;
        for(auto it : nums1)if(it%2)oddc++;
        return oddc==0;
    }
};