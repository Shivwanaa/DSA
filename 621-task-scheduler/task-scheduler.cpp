class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        queue<char>q;
        unordered_map<char,int>m;
        int maxe=0;
        for(auto i:tasks){
            m[i]++;
            maxe=max(maxe,m[i]);
        }
        int l=(maxe-1)*n+maxe;
        int c=0;
        for(auto i:m){
            if(i.second==maxe){
                c++;
            }
        }
        return c-1+l>tasks.size()?c-1+l:tasks.size();
    }
};