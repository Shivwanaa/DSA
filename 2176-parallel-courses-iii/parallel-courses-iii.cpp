class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>tim(n+1,0);
        queue<pair<int,int>>q;
        unordered_map<int,int>in;
        unordered_map<int,vector<int>>m;
        for(int i=1;i<=n;i++){
            in[i]=0;
        }
        for(auto i:relations){
            m[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        for(auto i:in){
            if(i.second==0){
                q.push({time[i.first-1],i.first});
                tim[i.first-1]=time[i.first-1];
            }
        }
        int ans=0;
        while(q.size()){
            auto[t,f]=q.front();
            q.pop();
            ans=max(ans,tim[f-1]);
            for(auto i:m[f]){
                in[i]--;
                tim[i-1]=max(tim[i-1],tim[f-1]+time[i-1]);
                if(in[i]==0){
                    q.push({tim[i-1],i});
                }

            }
        }
        return ans;
    }
};