class Solution {
public:
    int maxStarSum(vector<int>& vals, vector<vector<int>>& edges, int k) {
        unordered_map<int,int>in;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<vals.size();i++){
            in[i]=0;
            m[i]={};
        }
        for(auto i:edges){
            in[i[0]]++;
            in[i[1]]++;
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        auto comp=[&vals](int a,int b){
            return vals[a]>vals[b];//min heap
        };
        int ans=-1e9;
        for(auto i:in){
            int a=vals[i.first];
            if(i.second>=k){
                priority_queue<int,vector<int>,decltype(comp)>q(comp);
                for(auto j:m[i.first]){
                    q.push(j);
                    if(q.size()>k){
                        q.pop();
                    }
                }
                while(q.size()){
                    if(vals[q.top()]>0){
                    a=a+vals[q.top()];}
                    q.pop();
                }
            }
            else{
                for(auto j:m[i.first]){
                    if(vals[j]>0){
                        a=a+vals[j];
                    }
                }
            }
            ans=max(ans,a);
        }
        return ans;
    }
};