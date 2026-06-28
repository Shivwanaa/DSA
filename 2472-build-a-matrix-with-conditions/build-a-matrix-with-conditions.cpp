class Solution {
public:
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        vector<vector<int>>ans(k,vector<int>(k,0));
        //find row then colounm
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        for(int i=1;i<=k;i++){
            in[i]=0;
            m[i]={};
        }
        for(auto i:rowConditions){
            m[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        queue<int>q;
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
        }
        vector<int>rows;
        while(q.size()){
            auto f=q.front();
            q.pop();
            rows.push_back(f);
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(rows.size()<k){
            rows={};
        }
        for(int i=1;i<=k;i++){
            in[i]=0;
            m[i]={};
        }
        for(auto i:colConditions){
            m[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        queue<int>q1;
        for(auto i:in){
            if(i.second==0){
                q1.push(i.first);
            }
        }
        vector<int>col;
        while(q1.size()){
            int f=q1.front();
            q1.pop();
            col.push_back(f);
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q1.push(i);
                }
            }
        }
        cout<<col.size();
        if(col.size()<k){
            col={};
        }
        if(col.empty()||rows.empty()){
            return {};
        }
        for(int i=0;i<k;i++){
            for(int j=0;j<k;j++){
                if(rows[i]==col[j]){
                    ans[i][j]=rows[i];
                }
            }
        }
        return ans;
    }
};