class Solution {
public:
    int smallestCommonElement(vector<vector<int>>& mat) {
        map<int,int>m;
        for(auto i:mat){
            for(auto j:i){
                m[j]++;
            }
        }
        for(auto i:m){
            if(i.second==mat.size()){
                return i.first;
            }
        }
        return -1;
    }
};