class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        unordered_map<int,vector<pair<int,double>>>m;
        int j=0;
        for(auto i:edges){
            m[i[0]].push_back({i[1],succProb[j]});
            m[i[1]].push_back({i[0],succProb[j]});
            j++;
        }
        auto comp=[](pair<int,double>a,pair<int,double>b){
            return a.second<b.second;
        };
        priority_queue<pair<int,double>,vector<pair<int,double>>,decltype(comp)>q(comp);
        q.push({start_node,1});
        unordered_set<int>v;
        while(q.size()){
            auto[node,prob]=q.top();
            q.pop();
            if(node==end_node){
                return prob;
            }
            if(v.count(node)){
                continue;
            }
            v.insert(node);
            for(auto i:m[node]){
                // cout<<i.second<<endl;
                q.push({i.first,i.second*prob});
            }
        }
        return 0;
    }
};