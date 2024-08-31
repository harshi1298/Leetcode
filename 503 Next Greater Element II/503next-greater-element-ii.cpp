class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int maxindex=0;
        int maxnum=nums[0];
        for(int i=0;i<nums.size();i++){
            if(maxnum<nums[i]){
                maxnum=nums[i];
                maxindex=i;
                }
        }
        vector<int>ans(nums.size());
        stack<int>st;
        st.push(maxnum);
        ans[maxindex]=-1;
        for(int l=maxindex-1;l>=0;l--){
          while(!st.empty() && st.top()<=nums[l]){
            st.pop();
          }
          if(!st.empty())
          ans[l]=st.top();
          else ans[l]=-1;
          st.push(nums[l]);
        }
        for(int l=nums.size()-1;l>maxindex;l--){
          while(!st.empty() &&st.top()<=nums[l]){
            st.pop();
          }
          if( !st.empty() )
          ans[l]=st.top();
          else ans[l]=-1;
          st.push(nums[l]);
        }
        return ans;
    }
};