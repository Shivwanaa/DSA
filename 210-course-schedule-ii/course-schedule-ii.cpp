class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        for(int i=0;i<numCourses;i++){
            in[i]=0;
            m[i]={};
        }
        for(auto i:prerequisites){
            m[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        queue<int>q;
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
        }
        while(q.size()){
            int t=q.front();
            q.pop();
            ans.push_back(t);
            for(auto j:m[t]){
                in[j]--;
                if(in[j]==0)
                q.push(j);
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};