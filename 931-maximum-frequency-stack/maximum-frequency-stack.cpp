class FreqStack {
public:
priority_queue<vector<int>>q;
unordered_map<int,int>m;
int idx=0;
    FreqStack() {
    }
    void push(int val) {
        m[val]++;
        q.push({m[val],idx++,val});
    }
    
    int pop() {
        vector<int>a=q.top();
        q.pop();
        m[a[2]]--;
        return a[2];
    }
};

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */