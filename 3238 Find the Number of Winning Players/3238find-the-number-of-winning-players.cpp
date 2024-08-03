class Solution {
public:
    int winningPlayerCount(int n, vector<vector<int>>& pick) {
        unordered_map<int,vector<int>> m;
        int ans=0;
        for(int i=0;i<pick.size();i++){
            m[pick[i][0]].push_back(pick[i][1]);
        }
        for(auto i:m){
             if(i.first==0 && i.second.size()==1)ans++;
           sort(i.second.begin(),i.second.end());
            int count=1;
            for(int j=1;j<i.second.size();j++){
                while(j<i.second.size()&&i.second[j]==i.second[j-1]){ count++;
                                                  j++;}

                    if(count>i.first){
                        ans++;
                        count=0;
                        break;
                    }
                
                    count=1;
            }
        }
        return ans;
    }
};