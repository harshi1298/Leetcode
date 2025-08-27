class Solution {
public:
    string removeKdigits(string nums, int k) {
        stack<char>st;
        int n=nums.size();
        for(int i=0;i<n;i++){
            if(nums[i]=='0' && st.empty())continue;
            while(k && !st.empty() && st.top()>nums[i]){
                st.pop();
                k--;
            }
            st.push(nums[i]);
        }
        while(!st.empty() && (k)){
            st.pop();
            k--;
        }
        string ans="";
        while(!st.empty()){
           ans.push_back(st.top());
           st.pop();
        }
        while(ans.length() && ans.back()=='0')ans.pop_back();
        reverse(ans.begin(),ans.end());
        return ans.length()==0?"0":ans;
    }
};