class Solution {
public:
    double frogPosition(int n, vector<vector<int>>& edges, int t, int target) {
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        queue<tuple<int,int,double>>q;
        q.push({1,t,1.0});
        double ans=1.0;
        
        vector<bool>v(n+1,0);
        v[1]=1;
        while(q.size()){
            auto[node,level,prob]=q.front();
            q.pop();
            v[node]=1;
            int len=0;
            for(auto nei : m[node]) {
    if(!v[nei])
        len++;
}
            if(node == target) {
                if(level == 0 || len == 0)
                    return prob;
                continue;
            }
            if(level<=0){
                continue;
            }
            for(auto i:m[node]){
                if(!v[i]){
                    v[i]=1;
                q.push({i,level-1,prob/double(len)});
                }
            }
        }
        return 0.0;
    }
};