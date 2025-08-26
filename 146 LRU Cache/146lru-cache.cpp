class LRUCache {
public:
    int cap;
    list<pair<int,int>>dll;
    unordered_map<int,list<pair<int,int>>::iterator>mapp;
    LRUCache(int capacity) {
      cap=capacity;  
    } 
    
    int get(int key) {
        if(mapp.find(key)==mapp.end())return -1;
        dll.splice(dll.end(),dll,mapp[key]);
        return mapp[key]->second;
    }
    
    void put(int key, int value) {
        if(mapp.find(key)!=mapp.end()){
            mapp[key]->second=value;
            dll.splice(dll.end(),dll,mapp[key]);
        }
        else{
            if(mapp.size()==cap){
              int t=dll.begin()->first;
              dll.pop_front();
              mapp.erase(t);
            }
            dll.push_back(make_pair(key,value));
            mapp[key]=--dll.end();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */