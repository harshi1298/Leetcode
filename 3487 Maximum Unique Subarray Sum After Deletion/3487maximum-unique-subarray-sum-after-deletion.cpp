class Solution {
public:
    int maxSum(vector<int>& nums) {
        unordered_set<int>st;
        for(int i:nums){
            if(i >= 0)
            st.insert(i);
        }
        int sum = 0;
        for(int i:st){
            sum += i;
        }
        if(st.empty()){
            return *max_element(nums.begin(),nums.end());
        }
        return sum;
    }
};