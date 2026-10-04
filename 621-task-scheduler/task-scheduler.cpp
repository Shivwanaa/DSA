class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0){
            return tasks.size();
        }
        unordered_map<char,int>m;
        int c=0;
        for(auto i:tasks){
            m[i]++;
            
        }
        for(auto i:m){
            c=max(c,i.second);
        }
        int temp=(c-1)*n+c;
        int a=0;
        for(auto i:m){
            if(i.second==c){
                a++;
            }
        }
        return temp+a-1>tasks.size()?temp+a-1:tasks.size();
    }
};