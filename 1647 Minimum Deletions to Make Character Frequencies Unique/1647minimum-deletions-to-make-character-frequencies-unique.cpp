class Solution {
public:
    int minDeletions(string s) {
        vector<int> fre(26, 0);
        int ans=0;
        for (char c : s) fre[c - 'a']++;
        sort(fre.begin(), fre.end(), greater<int>());
        int i=1;
        while(i<26 && fre[i]>0){
            if(fre[i]>=fre[i-1]){
                if(fre[i-1]==0)ans+=fre[i];
                else
                  ans+=fre[i]-fre[i-1]+1;
                fre[i]=max(0,fre[i-1]-1);
            }
            i++;
        }
        return ans;
    }
};
