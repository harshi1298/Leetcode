class TaskManager {
private: 
    unordered_map<int,int>ttouser;
    unordered_map<int,int>ttop;
    priority_queue<pair<int,int>>pq;
public:
    TaskManager(vector<vector<int>>& tasks) {
        for(auto it : tasks){
            ttouser[it[1]]=it[0];
            ttop[it[1]]=it[2];
            pq.push({it[2],it[1]});
        }
    }
    
    void add(int userId, int taskId, int priority) {
        ttouser[taskId]=userId;
        ttop[taskId]=priority;
        pq.push({priority,taskId});
    }
    
    void edit(int taskId, int newPriority) {
        ttop[taskId]=newPriority;
        pq.push({newPriority,taskId});
    }
    
    void rmv(int taskId) {
        ttouser.erase(taskId);
        ttop.erase(taskId);
    }
    
    int execTop() {
        while(!pq.empty() && (ttouser.find(pq.top().second)==ttouser.end() || ttop[pq.top().second]!=pq.top().first))pq.pop();
        if(pq.empty())return -1;
        int taskId=pq.top().second;
        int ans=ttouser[taskId];
        rmv(taskId);
        return ans;
    }
};

/**
 * Your TaskManager object will be instantiated and called as such:
 * TaskManager* obj = new TaskManager(tasks);
 * obj->add(userId,taskId,priority);
 * obj->edit(taskId,newPriority);
 * obj->rmv(taskId);
 * int param_4 = obj->execTop();
 */