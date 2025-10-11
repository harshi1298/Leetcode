class ExamTracker {
public:
    map<int,int>mapp;
    vector<long long>suff;
    int key=0;
    ExamTracker() {
        mapp[0]=key;
        suff.push_back(0);
        key++;
    }
    
    void record(int time, int score) {
        mapp[time]=key;
        suff.push_back(suff.back()+score);
        key++;
    }
    
    long long totalScore(int st, int et) {
        auto it =mapp.lower_bound(st);
        int se=prev(it)->second;
        long long sub=suff[se];
        it=mapp.lower_bound(et);
        if(it!=mapp.end() && it->first>et && it->second-1<=se)return 0;
        if(it!=mapp.end() && it->first==et)return suff[it->second]-sub;
        if(it==mapp.end() || it->first>et)return suff[(prev(it))->second]-sub;
       
        return suff[it->second]-sub;
    }
};

/**
 * Your ExamTracker object will be instantiated and called as such:
 * ExamTracker* obj = new ExamTracker();
 * obj->record(time,score);
 * long long param_2 = obj->totalScore(startTime,endTime);
 */