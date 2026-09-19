class Solution {
public:
    bool check(unordered_map<int,vector<int>>&m,int s,int d,unordered_set<int>&v){
        if(s==d){
            return true;
        }
        if(v.count(s)){
            return false;
        }
        v.insert(s);
        for(auto i:m[s]){
            if(check(m,i,d,v)){
                return true;
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        unordered_set<int>v;
        return check(m,source,destination,v);
    }
};