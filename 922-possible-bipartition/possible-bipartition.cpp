class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        unordered_map<int,vector<int>>m;
        for(auto i:dislikes){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        vector<int>c(n+1,0);
        for(int i=1;i<=n;i++){
            if(c[i]!=0){
                continue;
            }
            c[i]=-1;
            queue<int>q;
            q.push(i);
            while(q.size()){
                int f=q.front();
                q.pop();
                for(auto j:m[f]){
                    if(c[f]==c[j]){
                        return false;
                    }
                    else if(c[j]==0){
                        c[j]=-c[f];
                        q.push(j);
                    }
                }
            }
            
        }
        return true;
    }
};