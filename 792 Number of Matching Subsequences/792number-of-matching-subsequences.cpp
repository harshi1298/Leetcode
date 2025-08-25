class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        vector<vector<int>>arr(26);
        int ans=0;
        for(int i=0;i<s.length();i++)arr[s[i]-'a'].push_back(i);
        for(auto it : words){
            bool flag=1;
            int x=-1;
            for(auto c : it){
                auto l=upper_bound(arr[c-'a'].begin(),arr[c-'a'].end(),x);
                if(l==arr[c-'a'].end()){flag=0;break;}
                else x=*l;
            }
            ans+=flag;
        }
        return ans;
    }
};