class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int>in;
        vector<int>ans;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<numCourses;i++){
            in[i]=0;
            m[i]={};
        }
        for(auto i:prerequisites){
            in[i[0]]++;
            m[i[1]].push_back(i[0]);
        }
        queue<int>q;
        for(auto i:in){
            if(i.second==0){
                q.push(i.first);
            }
        }
        while(q.size()){
            int course=q.front();
            q.pop();
            ans.push_back(course);
            for(auto i:m[course]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(ans.size()!=numCourses){
            return {};
        }
        return ans;
    }
};