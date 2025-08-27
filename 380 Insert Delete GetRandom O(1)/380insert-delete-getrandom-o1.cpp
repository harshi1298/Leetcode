class RandomizedSet {
private:
    unordered_map<int,int>mapp;
    vector<int>arr;
public:
    RandomizedSet() {
    }
    bool insert(int val) {
        if(mapp.find(val)!=mapp.end())return false;
        arr.push_back(val);
        mapp[val]=arr.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(mapp.find(val)==mapp.end())return false;
        int last=arr.back();
        arr.pop_back();
        arr[mapp[val]]=last;
        mapp[last]=mapp[val];
        mapp.erase(val);
        return true;
    }
    
    int getRandom() {
        return arr[(int)rand()%(arr.size())];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */