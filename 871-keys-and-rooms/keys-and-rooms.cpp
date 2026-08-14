class Solution {
public:
    void check(int rno,vector<vector<int>>& rooms,int n,unordered_set<int>&v){
        if(v.count(rno)){
            return ;
        }
        v.insert(rno);
        for(auto i:rooms[rno]){
            if(!v.count(i)){
                check(i,rooms,n,v);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        unordered_set<int>v;
        check(0,rooms,rooms.size(),v);
        if(v.size()==rooms.size()){
            return true;
        }
        return false;
    }
};