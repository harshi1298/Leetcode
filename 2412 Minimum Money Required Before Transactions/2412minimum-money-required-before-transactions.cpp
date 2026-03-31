class Solution {
public:
    long long minimumMoney(vector<vector<int>>& transactions) {
        vector<vector<long long>>trans1,trans2;
        for(auto it : transactions){
            if(it[0]>it[1]){
                trans1.push_back(vector<long long>({it[0],it[1]}));
            }
            else trans2.push_back(vector<long long>({it[0],it[1]}));
        }
        sort(trans1.begin(),trans1.end(),[&](auto a,auto b){
            return a[1]<b[1];
        });
        sort(trans2.begin(),trans2.end(),[&](auto a,auto b){
            return a[0]>b[0];
        });
        long long req=0,ans=0;
        for(auto it : trans1){
            req+=it[0];
            ans=max(ans,req);
            req-=it[1];
        }
        for(auto it : trans2){
            req+=it[0];
            ans=max(ans,req);
            req-=it[1];
        }
        return ans;
    }
};