#include <bits/stdc++.h>
using namespace std;
class Solution
{
public:
    string makeFancyString(string s)
    {
        string ans = "";
        int count = 1, n = s.length();
        ans.push_back(s[0]);
        for (int i = 1; i < n; i++)
        {
            if (s[i] == s[i - 1])
                count++;
            else
                count = 1;
            if (count >= 3)
                continue;
            ans.push_back(s[i]);
        }
        return ans;
    }
};