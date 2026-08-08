class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        queue<pair<int,int>>q;
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        for(int i=1;i<=n;i++){
            m[i]={};
            in[i]=0;
        }
        for(auto i:relations){
            m[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        for(auto i:in){
            if(i.second==0){
                cout<<i.first<<endl;
                q.push({i.first,time[i.first-1]});
            }
        }
        int ans=0;
        vector<int>t(n+1,0);
        while(q.size()){
            auto[course,times]=q.front();
            q.pop();
            // t[course]=max(t[course],times);
            ans=max(ans,times);
            for(auto i:m[course]){
                t[i] = max(t[i], times);
                in[i]--;
                if(in[i]==0){
                    q.push({i,t[i]+time[i-1]});
                }
            }
        }
        return ans;
    }
};