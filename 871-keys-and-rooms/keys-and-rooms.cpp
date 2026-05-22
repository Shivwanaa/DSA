class Solution {
public:
    void check(vector<vector<int>>& rooms,unordered_set<int>&v,int curr){
        v.insert(curr);
        for(auto i:rooms[curr]){
            if(!v.count(i))
            check(rooms,v,i);
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>v;
        check(rooms,v,0);
        if(v.size()==rooms.size()){
            return true;
        }
        return false;
    }
};