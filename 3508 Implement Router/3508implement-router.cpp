#define tp tuple<int,int,int>
class Router {
public:
    list<tp> dll;                         
    set<tp> st;                          
    unordered_map<int, vector<int>> dstMap; 
    int cap;
    Router(int memoryLimit) {
        cap = memoryLimit;
    }

    bool addPacket(int src, int dst, int ts) {
        if (st.find({src,dst,ts}) != st.end()) return false;

        if ((int)dll.size() == cap) {
            auto [t, s, d] = dll.front();
            st.erase({s,d,t});
            dll.pop_front();
            auto &vec = dstMap[d];
            auto it = lower_bound(vec.begin(), vec.end(), t);
            if (it != vec.end()) vec.erase(it);
            if (vec.empty()) dstMap.erase(d);
        }

        dll.push_back({ts, src, dst});
        st.insert({src,dst,ts});
        auto &vec = dstMap[dst];
        auto it = upper_bound(vec.begin(), vec.end(), ts);
        vec.insert(it, ts);

        return true;
    }

    vector<int> forwardPacket() {
        if (dll.empty()) return {};

        auto [t, src, dst] = dll.front();
        st.erase({src,dst,t});
        dll.pop_front();

        auto &vec = dstMap[dst];
        auto it = lower_bound(vec.begin(), vec.end(), t);
        if (it != vec.end()) vec.erase(it);
        if (vec.empty()) dstMap.erase(dst);

        return {src, dst, t};
    }

    int getCount(int dst, int stime, int etime) {
        if (!dstMap.count(dst)) return 0;
        if(dll.size()==0)return 0;
        stime=max(stime,get<0>(*dll.begin()));
        auto &vec = dstMap[dst];
        auto it1 = lower_bound(vec.begin(), vec.end(), stime); 
        auto it2 = upper_bound(vec.begin(), vec.end(), etime);

        return distance(it1, it2); 
    }
};
