class Solution {
public:
    int minDeletion(string s, int k) {
        unordered_map<char,int>mapp;
        for(int i=0;i<s.length();i++)mapp[s[i]]++;
        int ans=0;
        auto it=mapp.begin();
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& [ch, count] : mapp) {
            pq.push(count);
        }
        while(pq.size()>k){
            ans+=pq.top();
            pq.pop();
        }
        return ans;
    }
};