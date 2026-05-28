class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        vector<int>ans;
        unordered_map<int,int>in;
        unordered_map<int,vector<int>>m;
        for(auto i:edges){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
            in[i[0]]++;
            in[i[1]]++;
        }
        if(n==1){
            return {0};
        }
        queue<int>q;
        for(auto i:in){
            if(i.second==1){
                q.push(i.first);
            }
        }
        while(q.size()){
            if(n<=2){
                while(q.size()){
                    ans.push_back(q.front());
                    q.pop();
                }
            }
            int s=q.size();
            for(int i=0;i<s;i++){
                int f=q.front();
                q.pop();
                n--;
                for(auto j:m[f]){
                    in[j]--;
                    if(in[j]==1){
                        q.push(j);
                    }
                }
            }
        }
        return ans;
    }
};