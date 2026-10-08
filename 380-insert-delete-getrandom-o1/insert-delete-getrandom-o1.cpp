class RandomizedSet {
public:
unordered_map<int,int>m;
vector<int>a;

    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(m.find(val)!=m.end()){
            return false;
        }
        a.push_back(val);
        m[val]=a.size()-1;
        return true;
    }
    bool remove(int val) {
        if(m.find(val)==m.end()){
            return false;
        }
        int i=m[val];
        if(i==a.size()-1){
            a.pop_back();
            m.erase(val);
            return true;

        }
        m[a[a.size()-1]]=i;
        a[i]=a[a.size()-1];
        a.pop_back();
        m.erase(val);
        return true;
    }
    
    int getRandom() {
        int x=rand()%a.size();
        return a[x];
        
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */