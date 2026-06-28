class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes, vector<vector<string>>& ingredients, vector<string>& supplies) {
        unordered_map<string,vector<string>>m;
        unordered_map<string,int>in;
        int k=0;
        for(auto i:ingredients){
            for(auto j:i){
                in[j]=0;
            }
        }
        for(auto i:ingredients){
            for(auto j:i){
                m[j].push_back(recipes[k]);
                in[recipes[k]]++;
            }
            k++;
        }
        unordered_set<string>sup;
        for(auto i:supplies){
            sup.insert(i);
        }
        unordered_set<string>rep;
        for(auto i:recipes){
            rep.insert(i);
        }
        queue<string>q;
        for(auto i:in){
            if(i.second==0 && sup.count(i.first)){
                q.push(i.first);
            }
        }
        vector<string>ans;
        while(q.size()){
            string f=q.front();
            q.pop();
            if(rep.count(f)){
                ans.push_back(f);
            }
            for(auto i:m[f]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        return ans;
    }
};