class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        set<int>st;
        for(auto it : nums){
            st.insert(it);
        }
        vector<int>ans;
        int i=0;
        for(auto it=st.rbegin();it!=st.rend() && i<k;it++,i++){
            ans.push_back(*it);
        }
        return ans;
    }
};