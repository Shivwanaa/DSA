class PhoneDirectory {
public:
priority_queue<int,vector<int>,greater<int>>q;
unordered_set<int>av;
    PhoneDirectory(int maxNumbers) {
        for(int i=0;i<maxNumbers;i++){
            q.push(i);
            av.insert(i);
        }
    }
    
    int get() {
        int a= q.size()?q.top():-1;
        if(q.size()){
            q.pop();
        }
        if(a!=-1){
            av.erase(a);
        }
        return a;
    }
    
    bool check(int number) {
        if(av.count(number)){
            return true;
        }
        return false;
    }
    
    void release(int number) {
        if(!av.count(number)){
        av.insert(number);
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