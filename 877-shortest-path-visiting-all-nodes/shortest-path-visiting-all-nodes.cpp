class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        queue<pair<int,int>>q;
        for(int i=0;i<graph.size();i++){
            int m=1<<i;
            q.push({i,m});
        }
        set<pair<int,int>>v;
        int bit_act=(1<<graph.size())-1;
        int ans=0;

        while(q.size()){
            int s=q.size();
            for(int i=0;i<s;i++){
                auto[node,mask]=q.front();
                q.pop();
                if(v.count({node,mask})){
                    continue;
                }
                v.insert({node,mask});
                if(mask==bit_act){
                    return ans;
                }
                for(auto k:graph[node]){
                    int bit_temp=(1<<k)|mask;
                    if(v.count({k,mask})){
                        continue;
                    }
                    q.push({k,bit_temp});
                }
            }
            ans++;
        }
        return ans;
    }
};