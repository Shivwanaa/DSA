class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<char,int>m;
        for(auto i:tasks){
            m[i]++;
        }
        int l=0;
        for(auto i:m){
            l=max(l,i.second);
        }
        int c=0;
        for(auto i:m){
            if(l==i.second){
                c++;
            }
        }
        int maxi=l+(l-1)*n+c-1;
        return tasks.size()>maxi?tasks.size():maxi;
    }
};