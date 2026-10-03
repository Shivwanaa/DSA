class Node{
    public:
    int key;
    int val;
    Node*next=nullptr;
    Node*prev=nullptr;
    Node(int key,int val){
        this->key=key;
        this->val=val;
    }
};
class LRUCache {
public:
Node*first=new Node(-1,-1);
Node*last=new Node(-1,-1);
unordered_map<int,Node*>m;
int cap;
    LRUCache(int capacity) {
        first->next=last;
        last->prev=first;
        cap=capacity;
    }
    
    int get(int key) {
        if(m.find(key)!=m.end()){
            remove(m[key]);
            insert(m[key]);
            return m[key]->val;
        }
        return -1;
    }
    void remove(Node*del){
        del->prev->next=del->next;
        del->next->prev=del->prev;
        return;
    }
    void insert(Node*d){
        last->prev->next=d;
        d->prev=last->prev;
        last->prev=d;
        d->next=last;
    }
    void put(int key, int value) {
        if(m.find(key)!=m.end()){
            remove(m[key]);
            m.erase(key);
            
        }
        Node*add=new Node(key,value);
        insert(add);
        m[key]=add;
        if(m.size()>cap){
            
            m.erase(first->next->key);
            remove(first->next);
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */