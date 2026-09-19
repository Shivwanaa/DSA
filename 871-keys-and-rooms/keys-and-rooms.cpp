class Solution {
public:
    void check(unordered_map<int,vector<int>>&m,int src,unordered_set<int>&v){
        if(v.count(src)){
            return;
        }
        v.insert(src);
        for(auto i:m[src]){
            if(!v.count(i))
            check(m,i,v);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_map<int,vector<int>>m;
        for(int i=0;i<rooms.size();i++){
            for(int j=0;j<rooms[i].size();j++){
                m[i].push_back(rooms[i][j]);
            }
        }
        unordered_set<int>v;
        check(m,0,v);
        if(v.size()==rooms.size()){
            return true;
        }
        return false;
    }
};