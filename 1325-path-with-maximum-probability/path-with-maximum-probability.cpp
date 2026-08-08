class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>m;
        for(int i=0;i<edges.size();i++){
            m[edges[i][0]].push_back({edges[i][1],double(succProb[i])});
            m[edges[i][1]].push_back({edges[i][0],double(succProb[i])});
        }
        priority_queue<pair<double,int>>pq;
        pq.push({1.0,start_node});
        int ans=0;
        vector<int>vist(n,0);
        vector<double>probs(n,-1);
        probs[start_node]=1.0;
        while(pq.size()){
            auto[prob,node]=pq.top();
            pq.pop();
            if(prob<probs[node]){
                continue;
            }
            if(node==end_node){
                return prob;
            }
            for(auto i:m[node]){
                if(probs[i.first]<prob*i.second){
                probs[i.first]=prob*i.second;
                pq.push({prob*i.second,i.first});
                }
            }
        }
        return 0.0;
    }
};