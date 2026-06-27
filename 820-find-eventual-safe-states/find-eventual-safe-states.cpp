class Solution {
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        vector<int>ans;
        int j=0;
        queue<int>q;
        for(auto i:graph){
            if(i.empty()){
                q.push(j);
            }
            j++;
        }
        int k=0;
        unordered_map<int,int>in;
        unordered_map<int,vector<int>>m;
        for(auto i:graph){
            for(auto j:i){
                in[k]++;
                m[j].push_back(k);
            }
            k++;
        }
        
        while(q.size()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};