class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int>st;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(nums[i]^nums[j]);
            }
        }
        unordered_set<int>st2;
        for(int i=0;i<n;i++){
            for(auto &it :st){
                st2.insert(nums[i]^it);
            }
        }
        return st2.size();
    }
};