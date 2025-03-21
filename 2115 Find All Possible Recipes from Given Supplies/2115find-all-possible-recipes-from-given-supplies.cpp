class Solution {
    bool ispossible(vector<string>& recipes,unordered_map<string,int>&r,unordered_map<string,bool>&s,vector<vector<string>>& ingredients,int i){
           if (s[recipes[i]]==true) return true;
           for(auto it:ingredients[i]){
            if(s.find(it)==s.end()){
                if(r.find(it)==r.end()){
                    return false;
                }
                else{
                    if(!ispossible(recipes,r,s,ingredients,r[it]))return s[recipes[i]]=false;
                }
            }
            else if(s[it]==false){
                return false;
            }
        }
        // cout<<recipes[i]<<" ";
        return s[recipes[i]]=true;
    }
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,int>r;
        int i=0;
        for(auto it :recipes){
            r[it]=i;
            i++;
        }
        unordered_map<string,bool>s;
        for(auto it :supplies){
            s[it]=true;
        }
        vector<string>ans;
        for(int i=0;i<recipes.size();i++){
           if(s.find(recipes[i]) != s.end()){
            if(s[recipes[i]]==true){
              ans.push_back(recipes[i]);
              }
             
           }
           else if(ispossible(recipes,r,s,ingredients,i)){
               ans.push_back(recipes[i]);
           }
        }
        return ans;
    }
};