class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            int n=1<<i;
            q.push({i,n});
        }
        int ans=0;
        set<pair<int,int>>v;
        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto[node,visit]=q.front();
                q.pop();
                if(v.count({node,visit})){
                    continue;
                }
                v.insert({node,visit});
                if(visit==(1<<graph.size())-1){
                    return ans;
                }
                for(auto k:graph[node]){
                    int bit_temp=(1<<k)|visit;
                    // if(v.count({k,bit_temp})){
                    //     continue;
                    // }
                    q.push({k,bit_temp});
                }
            }
            ans++;
        }
        return ans;
    }
};