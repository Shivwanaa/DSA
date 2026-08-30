class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        unordered_map<int,int>in;
        for(int i=0;i<n;i++){
            in[i]=0;
        }
        for(auto i:edges){
            in[i[1]]++;
        }
        vector<int>ans;
        for(auto i:in){
            if(i.second==0){
                ans.push_back(i.first);
            }
        }
        return ans;
    }
};