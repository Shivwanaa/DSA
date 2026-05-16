class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        unordered_map<int,int>in;
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
        for(int i=0;i<numCourses;i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        int a=0;
        while(q.size()){
            int f=q.front();
            q.pop();
            a++;
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        if(a==numCourses){
            return true;
        }
        return false;
    }
};