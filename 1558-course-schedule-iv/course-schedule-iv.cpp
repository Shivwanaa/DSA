class Solution {
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        unordered_map<int,int>in;
        unordered_map<int,vector<int>>m;
        for(int i=0;i<numCourses;i++){
            in[i]=0;
            m[i]={};
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
        unordered_map<int, unordered_set<int>>preq;
        while(q.size()){
            int f=q.front();
            q.pop();
            for(auto i:m[f]){
                preq[i].insert(f);
                for(auto j:preq[f]){
                    preq[i].insert(j);
                }
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        vector<bool>ans;
        for(auto i:queries){
            ans.push_back(preq[i[1]].contains(i[0]));
        }
        return ans;
    }
};