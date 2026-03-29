class EventManager {
public:
    struct cmp {
        bool operator()(const pair<int,int>& a, const pair<int,int>& b) const {
            if (a.first != b.first)
                return a.first > b.first;   
            return a.second < b.second;     
        }
    };

    multiset<pair<int,int>, cmp> st;
    map<int,int>mapp;
    EventManager(vector<vector<int>>& events) {
        for(auto it: events){
            st.insert({it[1],it[0]});
            mapp[it[0]]=it[1];
        }
    }
    
    void updatePriority(int eventId, int newp) {
        int op=mapp[eventId];
        st.erase({op,eventId});
        st.insert({newp,eventId});
        mapp[eventId]=newp;
    }
    
    int pollHighest() {
        if(st.empty()) return -1;
        auto it = st.begin();  
        int ans = it->second;
        mapp.erase(it->second);
        st.erase(it);
        return ans;
    }
};

/**
 * Your EventManager object will be instantiated and called as such:
 * EventManager* obj = new EventManager(events);
 * obj->updatePriority(eventId,newPriority);
 * int param_2 = obj->pollHighest();
 */