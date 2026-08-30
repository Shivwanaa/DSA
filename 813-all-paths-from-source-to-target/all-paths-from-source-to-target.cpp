class Solution {
public:
vector<vector<int>>ans;
    void check(int node,vector<vector<int>>& graph,vector<int>tp){
        tp.push_back(node);
        if(node==graph.size()-1){
            ans.push_back(tp);
        }
        for(auto i:graph[node]){
            check(i,graph,tp);
        }
        // ans.push_back(tp);
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        check(0,graph,{});
        return ans;
    }
};