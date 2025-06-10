#include <bits/stdc++.h>
using namespace std;
#define pr pair<int, char>
class Solution
{
public:
    string minimizeStringValue(string s)
    {
        priority_queue<pr, vector<pr>, greater<pr>> pq;
        map<char, int> mapp;
        int n = s.length();
        for (auto it : s)
        {
            mapp[it]++;
        }
        for (auto it : mapp)
            if (it.first != '?')
                pq.push(make_pair(it.second, it.first));
        vector<char> temp;
        for (int i = 0; i < n; i++)
        {
            if (s[i] != '?')
            {
            }
            else
            {
                bool flag = true;
                for (int i = 0; i < 26; i++)
                {
                    if (mapp.find(i + 'a') == mapp.end())
                    {
                        mapp[i + 'a']++;
                        pq.push(make_pair(1, i + 'a'));
                        temp.push_back(i + 'a');
                        flag = false;
                        break;
                    }
                }
                if (flag)
                {
                    auto [f, ch] = pq.top();
                    pq.pop();
                    temp.push_back(ch);
                    pq.push(make_pair(f + 1, ch));
                }
            }
        }
        sort(temp.begin(), temp.end());
        int k = 0;
        for (int i = 0; i < n; i++)
        {
            if (s[i] == '?')
            {
                s[i] = temp[k];
                k++;
            }
        }
        return s;
    }
};