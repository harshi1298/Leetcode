class Solution {
public:
    int garbageCollection(vector<string>& garbage, vector<int>& travel) {
        int n=garbage.size();
        vector<int>arr(n);
        int total=0;
        unordered_set<char>st;
        for(int i=n-1;i>0;i--){
            string k=garbage[i];
            for(int j=0;j<k.length();j++){
                st.insert(k[j]);
                if(st.size()==3)break;
            }
            total+=k.length();
            arr[i-1]=max(arr[i],(int)st.size());
        }
        total+=garbage[0].length();
        int ans=0;
        for(int i=0;i<travel.size();i++){
            ans+=(travel[i]*arr[i]);
        }
        return ans+total;
    }
};