class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mapp;
        stack<int>st;
        int l=nums2.size();
        st.push(nums2[l-1]);
        mapp[st.top()]=-1;
        for(int i=l-2;i>-1;i--){
            while(!st.empty() && st.top()<nums2[i]){
                st.pop();
            }
            if(st.empty()){
                mapp[nums2[i]]=-1;
            }
            else{
                mapp[nums2[i]]=st.top();
            }
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(int i=0;i<nums1.size();i++){
            ans.push_back(mapp[nums1[i]]);
        }
        return ans;
    }
};