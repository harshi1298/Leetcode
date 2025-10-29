class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int>temp;
        for(auto &vec: bank){
            int c=0;
            for(auto it : vec){
                c+=(it-'0');
            }
            if(c>0)temp.push_back(c);
        }
        if(temp.size()<2)return 0;
        int ans=0;
        for(int i=1;i<temp.size();i++){
            ans+=(temp[i]*temp[i-1]);
        }
        return ans;
    }
};