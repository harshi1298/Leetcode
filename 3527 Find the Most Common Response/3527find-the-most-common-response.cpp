class Solution {
public:
    string findCommonResponse(vector<vector<string>>& responses) {
        int n = responses.size();
        vector<set<string>> arr(n);  
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < responses[i].size(); j++) {
                arr[i].insert(responses[i][j]);
            }
        }
        
        map<string, int> mapp;
        for (int i = 0; i < n; i++) {
            for (auto it : arr[i]) {
                mapp[it]++;
            }
        }
        
        int maxi = 0;
        string ans = "";
        for (auto &it : mapp) {
            if (it.second > maxi) {
                maxi = it.second;
                ans = it.first;
            } else if (it.second == maxi) {
                ans = min(ans, it.first);
            }
        }
        
        return ans;
    }
};
