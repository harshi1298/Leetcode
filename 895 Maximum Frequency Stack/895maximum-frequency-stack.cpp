class FreqStack {
private:
    unordered_map<int,int>freq;
    unordered_map<int,stack<int>>st;
    int maxi=0;
public:
    FreqStack() {
        
    }
    
    void push(int val) {
        freq[val]++;
        st[freq[val]].push(val);
        maxi=max(maxi,freq[val]);
    }
    
    int pop() {
        while(maxi>0){
            while(!st[maxi].empty() && freq[st[maxi].top()]!=maxi){
                st[maxi].pop();
            }
            if(st[maxi].empty())maxi--;
            else break;
        }
        int k=st[maxi].top();
        st[maxi].pop();
        freq[k]--;
        return k;
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */