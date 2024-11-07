class Solution {
public:
    int MOD=pow(10,9)+7;
    int lengthAfterTransformations(string s, int t) {
        int n=s.length();
        vector<int> freq(26,0);
        for(int i=0;i<n;i++){
            freq[s[i]-'a']++;
        }
        for(int i=0;i<t;i++){
            int temp=freq[25];
            for(int k=24;k>=0;k--){
                freq[k+1]=freq[k];
            }
            freq[0]=temp;
            freq[1]=(freq[1]+temp)%MOD;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans=(ans+freq[i])%(MOD);
        }   
        return ans;
    }
};