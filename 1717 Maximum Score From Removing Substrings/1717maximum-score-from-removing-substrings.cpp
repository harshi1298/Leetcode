#include <bits/stdc++.h>
using namespace std;
class Solution
{
private:
    int solve(string s, int x, int y)
    {
        int n = s.length();
        stack<char> st;
        int ans = 0;
        for (int i = 0; i < n; i++)
        {
            if (!st.empty() && st.top() == 'a' && s[i] == 'b')
            {
                st.pop();
                ans += x;
            }
            else
            {
                st.push(s[i]);
            }
        }
        if (st.empty())
            return ans;
        string temp="";
        while(!st.empty()){
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(),temp.end());
        int t=temp.length();
        for(int i=0;i<t;i++){
            if(!st.empty() && st.top()=='b' && temp[i]=='a'){
                ans+=y;
                st.pop();
            }
            else {
                st.push(temp[i]);
            }
        }
        return ans;
    }

public:
    int maximumGain(string s, int x, int y)
    {
        string t = s;
        reverse(s.begin(), s.end());
        return max(solve(t, x, y), solve(s, y, x));
    }
};