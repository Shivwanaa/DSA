class MedianFinder {
public:
priority_queue<int>maxh;
priority_queue<int,vector<int>,greater<>>minh;
    MedianFinder() { 
    }
    void addNum(int num) {
        if(maxh.empty() || maxh.top()>=num){
            maxh.push(num);
        }
        else {
            minh.push(num);
        }
        while(maxh.size()>minh.size()+1){
            minh.push(maxh.top());
            maxh.pop();
        }
        while(minh.size()>maxh.size()){
            maxh.push(minh.top());
            minh.pop();
        }
    }
    
    double findMedian() {
        if(maxh.size()==minh.size()){
            return double(maxh.top()+minh.top())/2.0;
        }
        else{
            // if(minh.size()>maxh.size()){
            //     return double(minh.top());
            // }
            return double(maxh.top());
        }
    }
};

/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */