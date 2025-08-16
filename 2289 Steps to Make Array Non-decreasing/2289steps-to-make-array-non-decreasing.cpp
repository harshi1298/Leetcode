class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int,int>>st;
        int n=nums.size(),ans=0;
        for(int i=n-1;i>=0;i--){
            int t=0;
            while(!st.empty() && st.top().first<nums[i]){
                t=max(t+1,st.top().second);
                st.pop();
            }
            ans=max(ans,t);
            st.push({nums[i],t});
        }
        return ans;
    }
};