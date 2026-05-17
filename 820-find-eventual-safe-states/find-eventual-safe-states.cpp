class Solution {
public:
    bool check(vector<vector<int>>& graph,int node,unordered_set<int>&visting,unordered_set<int>&visted){
        if(visting.count(node)){
            return true;
        }
        if(visted.count(node)){
            return false;
        }
        visting.insert(node);
        for(auto i:graph[node]){
            if(check(graph,i,visting,visted)){
                return true;
            }
        }
        visting.erase(node);
        visted.insert(node);
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //now do dfs
        //visting set for curr recursion visted for completed that node
        unordered_set<int>visted;
        unordered_set<int>visting;
        vector<int>ans;
        //set-for terminal node
        unordered_set<int>terminal;
        for(int i=0;i<graph.size();i++){
            if(!check(graph,i,visting,visted)){
                ans.push_back(i);
            }
        }
        // for(auto i:visted){
        //     ans.push_back(i);
        // }
        sort(ans.begin(),ans.end());
        return ans;
    }
};