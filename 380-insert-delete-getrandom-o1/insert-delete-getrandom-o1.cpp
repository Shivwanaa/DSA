class RandomizedSet {
public:
unordered_set<int>v;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(v.count(val)){
            return false;
        }
        v.insert(val);
        return true;
    }
    
    bool remove(int val) {
        if(!v.count(val)){
            return false;
        }
        v.erase(val);
        return true;
    }
    
    int getRandom() {
        if(!v.empty()){
        return *next(v.begin(),rand()%v.size());
        }
        return 0;
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */