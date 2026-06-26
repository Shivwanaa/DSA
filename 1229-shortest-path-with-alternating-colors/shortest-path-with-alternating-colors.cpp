class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int>ans(n,1e9);
        queue<tuple<int,int,int>>q;
        unordered_map<int,vector<int>>r;
        unordered_map<int,vector<int>>b;
        for(auto i:redEdges){
            r[i[0]].push_back(i[1]);
        }
        for(auto i:blueEdges){
            b[i[0]].push_back(i[1]);
        }
        q.push({0,0,1});
        q.push({0,0,0});
        set<pair<int,int>>v;
        while(q.size()){
            auto [a,node,color]=q.front();
            q.pop();
            if(v.count({node,color})){
                continue;
            }
            v.insert({node,color});
            ans[node]=min(ans[node],a);
            if(color){
                for(auto i:b[node]){
                    q.push({a+1,i,0});
                }
            }
            else{
                for(auto i:r[node]){
                    q.push({a+1,i,1});
                }
            }
        }
        for(int i=0;i<ans.size();i++){
            if(ans[i]==1e9){
                ans[i]=-1;
            }
            
        }
        return ans;
    }
};