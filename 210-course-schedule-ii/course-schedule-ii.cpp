class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        queue<int>q;
        for(int i=0;i<numCourses;i++){
            m[i]={};
            in[i]=0;
        }
        for(auto i:prerequisites){
            m[i[1]].push_back(i[0]);
            in[i[0]]++;
        }
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
        }
        vector<int>ans;
        while(q.size()){
            int f=q.front();
            q.pop();
            ans.push_back(f);
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0)
                q.push(i);
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};