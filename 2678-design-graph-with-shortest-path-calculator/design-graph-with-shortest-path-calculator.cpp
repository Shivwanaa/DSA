class Graph {
public:
vector<vector<int>>gr;
int nodes=0;
vector<vector<int>>dist;
    Graph(int n, vector<vector<int>>& edges) {
        gr=edges;
        nodes=n;
        dist=vector<vector<int>>(n,vector<int>(n,1e9));
        for(auto i:gr){
            dist[i[0]][i[1]]=i[2];
        }
        for(int k=0;k<n;k++){
            for(int i=0;i<n;i++){
                for(int j=0;j<n;j++){
                    if(i==j){
                        dist[i][j]=0;
                    }
                    dist[i][j]=min(dist[i][j],dist[i][k]+dist[k][j]);
                }
            }
        }
    }
    
    void addEdge(vector<int> edge) {
        gr.push_back(edge);
        for(int i=0;i<nodes;i++){
            for(int j=0;j<nodes;j++){
                if(i==j){
                    dist[i][j]=0;
                }
                dist[i][j]=min(dist[i][j],dist[i][edge[0]]+dist[edge[1]][j]+edge[2]);
                }
            }
        
    }
    
    int shortestPath(int node1, int node2) {
        if(dist[node1][node2]==1e9){
            return -1;
        }
        return dist[node1][node2];
    }
};

/**
 * Your Graph object will be instantiated and called as such:
 * Graph* obj = new Graph(n, edges);
 * obj->addEdge(edge);
 * int param_2 = obj->shortestPath(node1,node2);
 */