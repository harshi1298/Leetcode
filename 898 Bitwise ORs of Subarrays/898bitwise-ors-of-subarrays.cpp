class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        int n=arr.size();
        unordered_set<int>st,cur;
        for(auto x : arr){
            unordered_set<int>next;
            next.insert(x);
            for(auto it : cur){
                next.insert(it |x);
            }
            st.insert(next.begin(),next.end());
            cur=next;
        }
        return st.size();
    }
};