class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int>suffix(arr.size()+1);
        vector<int>ans;
        for(int i=0;i<arr.size();i++)suffix[i+1]=(arr[i]^suffix[i]);
        for(int i=0;i<queries.size();i++){
            int left=queries[i][0];
            int right=queries[i][1];
            ans.push_back(suffix[left]^suffix[right+1]);
        }
        return ans;
    }
};