class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        int mf=0;
        for(auto i:tasks){
            m[i]++;
            mf=max(mf,m[i]);
        }
        int cm=0;
        for(auto i:m){
            if(i.second==mf){
                cm++;
            }
        }
        int a=(mf-1)*(n+1)+cm;
        return max(int(tasks.size()),a);
    }
};