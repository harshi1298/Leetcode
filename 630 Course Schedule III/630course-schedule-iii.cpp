#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int scheduleCourse(vector<vector<int>> &courses)
    {
        sort(courses.begin(), courses.end(), [](auto &a, auto &b)
             { return a[1] < b[1]; });

        priority_queue<int> pq;
        int total = 0;

        for (auto &course : courses)
        {
            int dur = course[0], last = course[1];
            total += dur;
            pq.push(dur);
            if (total > last)
            {
                total -= pq.top();
                pq.pop();
            }
        }

        return pq.size();
    }
};
