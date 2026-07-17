class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>c(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(c[i]!=0){
                continue;
            }
            queue<int>q;
            c[i]=-1;
            q.push(i);
            while(q.size()){
                int t=q.front();
                q.pop();
                for(auto i:graph[t]){
                    if(c[i]==c[t]){
                        return false;
                    }
                    else if(c[i]==0){
                        q.push(i);
                        c[i]=-c[t];
                    }
                }
            }
        }
        return true;
    }
};