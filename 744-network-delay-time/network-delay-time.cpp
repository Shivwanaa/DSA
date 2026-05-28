class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // if(n==k){
        //     return -1;
        // }
        map<pair<int,int>,int>main;
        unordered_map<int,vector<int>>m;
        for(auto i:times){
            m[i[0]].push_back(i[1]);
            main[{i[0],i[1]}]=i[2];
        }
        auto comp=[](pair<int,int>a,pair<int,int>b){
            return a.second>b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>pq(comp);
        pq.push({k,0});
        int ans=-1;
        unordered_set<int>v;
        while(pq.size()){
            auto [f,c]=pq.top();
            pq.pop();
            if(v.count(f)){
                continue;
            }
            ans=max(ans,c);
            v.insert(f);
            for(auto i:m[f]){
                if(!v.count(i))
                pq.push({i,c+main[{f,i}]});
            }
        }
       
        if(v.size()==n){
            return ans;
        }
        return -1;
    }
};