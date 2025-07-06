#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    bool isvalid(string &code, string &businessLine, bool isActive)
    {
        if (isActive == false)
        {
            return false;
        }
        if (!(businessLine == "electronics" || businessLine == "pharmacy" || businessLine == "grocery" || businessLine == "restaurant"))
        {
            return false;
        }
        for (int i = 0; i < code.size(); i++)
        {
            if (!(isalnum(code[i]) || code[i] == '_'))
            {
                return false;
            }
        }
        return true;
    }

public:
    vector<string> validateCoupons(vector<string> &code, vector<string> &businessLine, vector<bool> &isActive)
    {
        vector<int> temp;
        int n = code.size();
        for (int i = 0; i < n; i++)
        {
            if (isvalid(code[i], businessLine[i], isActive[i]))
            {
                temp.push_back(i);
            }
        }
        sort(temp.begin(), temp.end(), [&](int a, int b)
             { if (businessLine[a] == businessLine[b])
                   return code[a] < code[b];
               return businessLine[a] < businessLine[b]; });
        vector<string> result;
        for (int i : temp)
        {
            if (code[i].size() > 0)
                result.push_back(code[i]);
        }
        return result;
    }
};