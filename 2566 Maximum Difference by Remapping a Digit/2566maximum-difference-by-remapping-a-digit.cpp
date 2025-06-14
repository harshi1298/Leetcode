#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    int minMaxDifference(int num)
    {
        string s = to_string(num);
        int n = s.length();
        int maxi = 0, mini = INT_MAX;
        for (int i = 0; i < n; i++)
        {
            char t = s[i];
            string temp1 = "", temp2 = "";
            for (int j = 0; j < n; j++)
            {
                if (s[j] == t)
                {
                    temp1.push_back('9');
                    temp2.push_back('0');
                }
                else
                {
                    temp1.push_back(s[j]);
                    temp2.push_back(s[j]);
                }
            }
            maxi = max(maxi, stoi(temp1));
            mini = min(mini, stoi(temp2));
        }
        return maxi - mini;
    }
};