class Solution {
public:
    int minimumSemesters(int n, vector<vector<int>>& relations) {
        int sems=0;
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        for(int i=1;i<=n;i++){
            in[i]=0;
            m[i]={};
        }
        for(int i=0;i<relations.size();i++){
            m[relations[i][0]].push_back(relations[i][1]);
            in[relations[i][1]]++;
        }
        queue<pair<int,int>>q;
        for(int i=1;i<=n;i++){
            if(in[i]==0)
            q.push({i,1});
        }
        if(q.size()==0){
            return -1;
        }
        int a=0;
        while(q.size()){
            auto[f,no]=q.front();
            q.pop();
            a++;
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push({i,no+1});
                }
            }
            sems=no;
        }
        if(a==n){
            return sems;
        }
        return -1;
    }
};