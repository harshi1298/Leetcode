class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int l1=nums1.size();
        int l2=nums2.size();
        if(!(l1&1) && !(l2&1))return 0;
        else if(l1&1 && l2&1){
            int ans=0;
            for(auto i:nums1){
                ans=ans^i;
            }
             for(auto i:nums2){
                ans=ans^i;
            }
            return ans;
        }
        else if(l1&1){
            int ans=0;
            for(auto i:nums2){
                ans=ans^i;
            }
            return ans;
        }
        else{
             int ans=0;
            for(auto i:nums1){
                ans=ans^i;
            }
            return ans;
        }
    }
};