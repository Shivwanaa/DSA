class MyQueue {
public:
stack<int>s1;
stack<int>s2;
int front=0;
    MyQueue() {
        
    }
    
    void push(int x) {
        if(s1.empty()){
            front=x;
        }
        s1.push(x);
    }
    
    int pop() {
        if(s2.empty()){
            while(!s1.empty()){
            int a=s1.top();
            s2.push(a);
            s1.pop();
            }
        }
        int b=s2.top();
        s2.pop();
        return b;
    }
    
    int peek() {
        if(!s2.empty())
        return s2.top();
        return front;
    }
    
    bool empty() {
        if(s1.size()==0 && s2.empty()){
            return true;
        }
        return false;
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */