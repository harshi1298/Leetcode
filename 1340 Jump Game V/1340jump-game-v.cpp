class Solution {
public:
    int maxJumps(vector<int>& arr, int d) {
        int n=arr.size();
        vector<int> ans(n,0);
        vector<int> prevMaxIdx(n,-1),nextMaxIdx(n,n);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(!st.empty()) prevMaxIdx[i]=st.top();
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1;i>=0;i--){
            while(!st.empty() && arr[st.top()]<arr[i]){
                st.pop();
            }
            if(!st.empty()) nextMaxIdx[i]=st.top();
            st.push(i);
        }
        vector<int> indices(n);
        for(int i=0;i<n;i++) indices[i]=i;
        sort(indices.begin(),indices.end(),[&](int &a,int &b){
            return arr[a]<arr[b];
        });
        int answer=0;
        for(auto &idx:indices){
            int left=max(prevMaxIdx[idx]+1,idx-d);
            int right=min(nextMaxIdx[idx]-1,idx+d);
            int maxi=0;
            for(int k=left;k<=right;k++){
                maxi=max(maxi,1+ans[k]);
            }
            ans[idx]=maxi;
            answer=max(answer,ans[idx]);
        }
        return answer;
    }
};