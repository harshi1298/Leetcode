class Solution {
public:
    int maxSumDistinctTriplet(vector<int>& x, vector<int>& y) {
        unordered_set<int>st;
        unordered_map<int,int>mapp;
        int n=x.size();
        vector<int>temp;
        for(int i=0;i<n;i++){
            if(st.find(x[i])==st.end()){
                st.insert(x[i]);
                mapp[x[i]]=y[i];
            }
            else {
               mapp[x[i]]=max(mapp[x[i]],y[i]); 
            }
        }
        for(auto it : mapp){
            temp.push_back(it.second);
        }
        sort(temp.begin(),temp.end());
        int k=temp.size();
        if(k<3)return -1;
        return temp[k-1]+temp[k-2]+temp[k-3];
    }
};