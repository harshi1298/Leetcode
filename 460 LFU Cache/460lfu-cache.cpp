class LFUCache {
    int cap, minFreq;
    unordered_map<int, list<pair<int,int>>::iterator> mapp; 
    unordered_map<int, list<pair<int,int>>> dll;        
    unordered_map<int, int> freq;                          

public:
    LFUCache(int capacity) {
        cap = capacity;
        minFreq = 0;
    }

    int get(int key) {
        if (cap == 0 || mapp.find(key) == mapp.end()) return -1;
        int f = freq[key];
        auto it = mapp[key];
        pair<int,int> node = *it;
        dll[f].erase(it);
        if (dll[f].empty()) {
            dll.erase(f);
            if (minFreq == f) minFreq++;
        }
        dll[f+1].push_back(node);
        mapp[key] = --dll[f+1].end();
        freq[key]++;
        return node.second;
    }

    void put(int key, int value) {
        if (cap == 0) return;

        if (mapp.find(key) != mapp.end()) {
            mapp[key]->second = value;
            get(key);
            return;
        }

        if (mapp.size() == cap) {
            auto node = dll[minFreq].front();
            int oldKey = node.first;
            dll[minFreq].pop_front();
            if (dll[minFreq].empty()) dll.erase(minFreq);
            mapp.erase(oldKey);
            freq.erase(oldKey);
        }
        dll[1].push_back({key,value});
        mapp[key] = --dll[1].end();
        freq[key] = 1;
        minFreq = 1;
    }
};
