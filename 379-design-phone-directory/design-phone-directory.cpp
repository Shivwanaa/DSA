class PhoneDirectory {
public:
unordered_set<int>av;

int num;
    PhoneDirectory(int maxNumbers) {
        num=maxNumbers;
        for(int i=0;i<maxNumbers;i++){
            av.insert(i);
        }
    }
    
    int get() {
        int a=-1;
        for(auto i:av){
             a=i;
            break;
        }
        av.erase(a);
        return a;
    }
    
    bool check(int number) {
        if(av.count(number)){
            return true;
        }
        return false;
    }
    
    void release(int number) {
        av.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */