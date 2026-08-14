class Solution {
public:
    double check(string n1,string n2,unordered_map<string,vector<pair<string,double>>>&m,unordered_set<string>v){
        if(n1==n2){
            return 1.0;
        }
        if(v.count(n1)){
            return -1.0;
        }
        v.insert(n1);
        for(auto i:m[n1]){
            if(!v.count(i.first)){
            double result = check(i.first, n2, m, v);
            if(result != -1.0) {
                return i.second * result;
            }
            }
        }
        return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>m;
        for(int i=0;i<equations.size();i++){
            m[equations[i][0]].push_back({equations[i][1],values[i]});
            m[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
        }
        vector<double> ans;

        for(auto i:queries){
            if(!m.count(i[0])||!m.count(i[1])){
                ans.push_back(-1.0);
            }
            else{
            unordered_set<string>v;
            ans.push_back(check(i[0],i[1],m,v));
            }
        }
        return ans;
    }
};