class FoodRatings {
private:
    struct compare{
        bool operator()(auto a,auto b)const{
            if(a.first==b.first)return a.second>b.second;
            return a.first<b.first;
        }
    };
    unordered_map<string,int>ntor;
    unordered_map<string,string>ntoc;
    unordered_map<string, priority_queue<pair<int,string>, vector<pair<int,string>>, compare>> prh;
public:
    FoodRatings(vector<string>& foods, vector<string>& cuisines, vector<int>& ratings) {
        int n=foods.size();
        for(int i=0;i<n;i++){
           ntor[foods[i]]=ratings[i];
           prh[cuisines[i]].push({ratings[i],foods[i]});
           ntoc[foods[i]]=cuisines[i];
        }
    }
    
    void changeRating(string food, int newRating) {
        ntor[food]=newRating;
        prh[ntoc[food]].push({newRating,food});
    }
    
    string highestRated(string cuisine) {
       
        while(! prh[cuisine].empty() && ntor[ prh[cuisine].top().second]!= prh[cuisine].top().first) prh[cuisine].pop();
        return  prh[cuisine].top().second;
    }
};

/**
 * Your FoodRatings object will be instantiated and called as such:
 * FoodRatings* obj = new FoodRatings(foods, cuisines, ratings);
 * obj->changeRating(food,newRating);
 * string param_2 = obj->highestRated(cuisine);
 */