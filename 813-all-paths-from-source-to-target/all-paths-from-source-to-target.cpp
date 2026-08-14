class Solution {
public:
vector<vector<int>>ans;
    void check(int node,vector<vector<int>>& graph,int n,vector<int>temp){
        if(node==n){
            temp.push_back(n);
            ans.push_back(temp);
            return;
        }
        temp.push_back(node);
        for(auto i:graph[node]){
            check(i,graph,n,temp);
        }
    }
    vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
        check(0,graph,graph.size()-1,{});
        return ans;
    }
};