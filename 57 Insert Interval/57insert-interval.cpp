#include <vector>
#include <algorithm>

using namespace std;

class Solution {
private:
    vector<vector<int>> merge(vector<vector<int>>& intervals, vector<vector<int>>& ans, int j, int n) { 
        for (int i = j; i < n; i++) {
            if (ans.back()[1] >= intervals[i][0]) {
                ans.back()[1] = max(intervals[i][1], ans.back()[1]);
            } else {
                ans.push_back(intervals[i]);
            }
        }
        return ans;
    }

public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0;
        if (intervals.empty()) {
            ans.push_back(newInterval);
            return ans;
        }
        while (i < intervals.size() && intervals[i][1] < newInterval[0]) {
            ans.push_back(intervals[i]);
            i++;
        }
        while (i < intervals.size() && intervals[i][0] <= newInterval[1]) {
            newInterval[0] = min(newInterval[0], intervals[i][0]);
            newInterval[1] = max(newInterval[1], intervals[i][1]);
            i++;
        }
        ans.push_back(newInterval);
        while (i < intervals.size()) {
            ans.push_back(intervals[i]);
            i++;
        }
        return ans;
    }
};
