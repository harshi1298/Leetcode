#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    string generateTag(string caption)
    {
        stringstream ss(caption);
        string word, ans = "#";
        bool first = true;
        while (ss >> word)
        {
            string temp = "";
            for (char c : word)
            {
                if (isalpha(c))
                {
                    temp += tolower(c);
                }
            }
            if (temp.empty())
                continue;

            if (first)
            {
                ans += temp; 
                first = false;
            }
            else
            {
                temp[0] = toupper(temp[0]);
                ans += temp;
            }

            if (ans.size() >= 100)
                break;
        }
        if (ans.size() > 100)
            ans = ans.substr(0, 100);
        return ans;
    }
};
