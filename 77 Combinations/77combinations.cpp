class Solution {
private:
    void solve(int n, int k, int i, vector<int>& arr, vector<vector<int>>& ans) {
        if (arr.size() == k) {
            ans.push_back(arr);
            return;
        }
        
        for (int l = i; l <= n; l++) {
            arr.push_back(l);        
            solve(n, k, l + 1, arr, ans); // Recur with the next number
            arr.pop_back();       
        }
    }

public:
    vector<vector<int>> combine(int n, int k) {
        vector<int> arr;
        vector<vector<int>> ans;
        solve(n, k, 1, arr, ans);
        return ans;
    }
};
