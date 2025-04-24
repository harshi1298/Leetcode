class MyCalendar {
public:
    set<pair<int,int>>st;
    MyCalendar() {
    
    }
    
    bool book(int s, int e) {
        bool flag=1;
        for(auto &it:st){
            if((s>=it.first && s<it.second) || (e>it.first && e<=it.second) || (s<=it.first && e>=it.second))flag=0;
        }
        if(flag)st.insert({s,e});
        return flag;
    }
};

// /
//   Your MyCalendar object will be instantiated and called as such:
//   MyCalendar obj = new MyCalendar();
//   bool param_1 = obj->book(startTime,endTime);
//  /