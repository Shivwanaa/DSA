class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        //djikistra
        unordered_map<int,vector<pair<int,double>>>m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back({edges[i][1],succProb[i]});
            m[edges[i][1]].push_back({edges[i][0],succProb[i]});
        }
        priority_queue<pair<double,int>>q;
        q.push({1,start_node});
        vector<double>dist(n,0);
        while(q.size()){
            auto[d,node]=q.top();
            q.pop();
            if(d<dist[node]){
                continue;
            }
            if(node==end_node){
                return d;
            }
            for(auto i:m[node]){
                if(d*i.second>dist[i.first]){
                    dist[i.first]=d*i.second;
                    q.push({d*i.second,i.first});
                }
            }
        }
        return 0;
    }
};