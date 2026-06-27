class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
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
        int c=0;
        while(q.size()){
            int f=q.front();
            q.pop();
            c++;
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(c==numCourses){
            return true;
        }
        return false;
    }
};