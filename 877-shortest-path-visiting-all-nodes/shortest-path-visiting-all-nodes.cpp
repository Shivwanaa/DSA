class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        //start with nodes having least no of connections and continue in the same way
        set<pair<int,int>>v;
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            q.push({i,1<<i});
            v.insert({i,1<<i});
        }
        int ans=0;
        while(q.size()){
            int l=q.size();
            for(int i=0;i<l;i++){
                auto[node,mask]=q.front();
                q.pop();
                if(mask==(1<<graph.size())-1){
                    return ans;
                }
                for(auto k:graph[node]){
                    int t=(mask|(1<<k));
                    if(v.count({k,t})){
                        continue;
                    }
                    v.insert({k,t});
                    q.push({k,t});
                }
            }
            ans++;
        }
        return -1;
    }
};