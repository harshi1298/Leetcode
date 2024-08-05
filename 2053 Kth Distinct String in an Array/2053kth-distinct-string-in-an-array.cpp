class Solution {
public:
    string kthDistinct(vector<string>& arr, int k) {
       unordered_map<string ,int> mapp;
       vector<string>temp;
        for( auto s :arr){
            if(!mapp[s]) temp.push_back(s);
            mapp[s]++;
        }
        int l=0;
        for(int i=0;i<temp.size();i++){
            if(mapp[temp[i]]==1) l++;
            if(l==k) return temp[i];
        }
        return "";
    }
};