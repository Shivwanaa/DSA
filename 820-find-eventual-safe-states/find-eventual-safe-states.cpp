class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        queue<int>q;
        for(int i=0;i<graph.size();i++){
            if(graph[i].empty()){
                q.push(i);
            }
        }
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        for(int i=0;i<graph.size();i++){
            m[i]={};
            in[i]=0;
        }
        for(int i=0;i<graph.size();i++){
            for(int j=0;j<graph[i].size();j++){
                m[graph[i][j]].push_back(i);
                in[i]++;
            }
        }
        while(q.size()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};