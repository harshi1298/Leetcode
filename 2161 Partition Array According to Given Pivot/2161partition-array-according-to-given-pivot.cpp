class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {
        vector<int> ans;
        int count=0;
        for(auto &it:nums){
            if(it<pivot) ans.push_back(it);
            count+=(it==pivot);
        }
        while(count--) ans.push_back(pivot);
        for(auto &it:nums){
            if(it>pivot) ans.push_back(it);
        }
        return ans;
    }
};