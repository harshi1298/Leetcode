class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),count=0;
        unordered_set<int>st;
        for(int i=n-1;i>=0;i--){
           if(st.find(nums[i])!=st.end()){
             break;
           }
           count++;
           st.insert(nums[i]);
        }
        return (n-count+2)/3;
    }
};