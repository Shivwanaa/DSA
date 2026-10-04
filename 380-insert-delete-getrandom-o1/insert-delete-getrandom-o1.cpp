class RandomizedSet {
public:
unordered_map<int,int>m;
vector<int>list;
int i=0;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()){
            return false;
        }
        m[val]=list.size();
        list.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        if(m.find(val)==m.end()){
            return false;
        }
        int idx=m[val];
        
        int last=list.back();
        list[idx]=last;
        m[last]=idx;
        list.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int x=rand()%list.size();
        return list[x];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */