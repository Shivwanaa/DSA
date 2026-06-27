class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int>ans;
        unordered_map<int,vector<int>>m;
        unordered_map<int,int>in;
        for(int i=0;i<numCourses;i++){
            m[i]={};
            in[i]=0;
        }
        for(auto i:prerequisites){
            m[i[0]].push_back(i[1]);
            in[i[1]]++;
        }
        queue<int>q;
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
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
        if(ans.size()!=numCourses){
            return {};
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};