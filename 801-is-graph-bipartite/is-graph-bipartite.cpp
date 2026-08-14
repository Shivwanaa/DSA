class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>c(graph.size(),0);
        for(int i=0;i<graph.size();i++){
            if(c[i]!=0){
                continue;
            }
            queue<int>q;
            q.push(i);
            c[i]=1;
            while(q.size()){
                int node=q.front();
                q.pop();

                for(auto j:graph[node]){
                    if(c[j]==c[node]){
                        return false;
                    }
                    else if(c[j]==0){
                        q.push(j);
                        c[j]=-c[node];
                    }
                }
            }
            
        }
        return true;
    }
};