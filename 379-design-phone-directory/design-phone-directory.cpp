class PhoneDirectory {
public:
vector<int>slots;
int idx=0;
priority_queue<int,vector<int>,greater<>>q;
    PhoneDirectory(int maxNumbers) {
        slots.resize(maxNumbers,0);
        for(int i=0;i<maxNumbers;i++){
            q.push(i);
        }
    }
    
    int get() {
        if(q.empty()){
            return -1;
        }
        slots[q.top()]=1;
        int ans=q.top();
        q.pop();
        
        return ans;
    }
    
    bool check(int number) {
        if(slots[number]==0){
            return 1;
        }
        return 0;
    }
    
    void release(int number) {
        if(slots[number]==1){
            slots[number]=0;
            q.push(number);
        }
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */