class Solution {
public:
    int hardestWorker(int n, vector<vector<int>>& logs) {
        sort(logs.begin(), logs.end(), [&](auto &a, auto &b) {
            if (a[1] == b[1]) return a[0] < b[0];
            return a[1] < b[1];
        });

        map<int,int> mapp;
        for (int i = 0; i < logs.size(); i++) {
            if (i == 0) {
                mapp[logs[i][1]] = logs[i][0]; 
            } else {
                if(mapp.find(logs[i][1] - logs[i-1][1])==mapp.end())mapp[logs[i][1] - logs[i-1][1]]=logs[i][0];
                else mapp[logs[i][1] - logs[i-1][1]]=min(logs[i][0], mapp[logs[i][1] - logs[i-1][1]]);
            }
        }

        return mapp.rbegin()->second;
    }
};
