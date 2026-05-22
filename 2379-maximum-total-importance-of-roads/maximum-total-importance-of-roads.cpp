class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        unordered_map<int,int>in;
        unordered_map<int,int>imp;
        for(int i=0;i<n;i++){
            in[i]=0;
            imp[i]=-1;
        }
        for(auto i:roads){
            in[i[0]]++;
            in[i[1]]++;
        }
        auto comp=[](pair<int,int>a,pair<int,int>b){
            return a.second<=b.second;
        };
        priority_queue<pair<int,int>,vector<pair<int,int>>,decltype(comp)>q(comp);
        for(auto i:in){
            q.push(i);
        }
        while(q.size()){
            imp[q.top().first]=n;
            n--;
            q.pop();
        }
        long long ans=0;
        for(auto i:roads){
            ans=ans+imp[i[0]]+imp[i[1]];
        }
        return ans;
    }
};