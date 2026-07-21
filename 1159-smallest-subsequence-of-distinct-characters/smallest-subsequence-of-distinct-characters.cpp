class Solution {
public:
    string smallestSubsequence(string s) {
        int n=s.length();
        unordered_map<char,int>mapp;
        unordered_set<int>vis;
        stack<int>st;
        for(auto it : s)mapp[it]++;
        for(auto it : s){
            mapp[it]--;
            if(vis.find(it)!=vis.end())continue;
            while(!st.empty() && st.top()>it && mapp[st.top()]>0){
                vis.erase(st.top());
                st.pop();
            }
            st.push(it);
            vis.insert(it);
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};