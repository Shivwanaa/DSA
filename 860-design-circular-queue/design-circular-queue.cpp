class MyCircularQueue {
public:
vector<int>temp;
int k;
    MyCircularQueue(int k) {
        this->k=k;
    }
    
    bool enQueue(int value) {
        if(temp.size()==k){
            return false;
        }
        temp.push_back(value);
        return true;
    }
    
    bool deQueue() {
        if(!temp.size()){
            return false;
        }
        temp.erase(temp.begin());
        return true;
    }
    
    int Front() {
        return temp.size()?temp[0]:-1;
    }
    
    int Rear() {
        return temp.size()?temp[temp.size()-1]:-1;
    }
    
    bool isEmpty() {
        if(temp.size()){
            return false;
        }
        return true;
    }
    
    bool isFull() {
        if(temp.size()==k){
            return true;
        }
        return false;
    }
};


/**
 * Your MyCircularQueue object will be instantiated and called as such:
 * MyCircularQueue* obj = new MyCircularQueue(k);
 * bool param_1 = obj->enQueue(value);
 * bool param_2 = obj->deQueue();
 * int param_3 = obj->Front();
 * int param_4 = obj->Rear();
 * bool param_5 = obj->isEmpty();
 * bool param_6 = obj->isFull();
 */