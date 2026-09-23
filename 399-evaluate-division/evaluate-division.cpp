class Solution {
public:
vector<double>ans;
    double check(string start,string end,unordered_map<string,vector<pair<string,double>>>&m,unordered_set<string>&s){
        if(start==end){
            return 1.0;
        }
        s.insert(start);
        for(auto i:m[start]){
            if(!s.count(i.first)){
                double temp = check(i.first, end, m, s);
                if(temp!=-1) {
                    return i.second*temp;
                }
            }
        }
        return -1.0;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        unordered_map<string,vector<pair<string,double>>>m;
        for(int i=0;i<equations.size();i++){
            m[equations[i][1]].push_back({equations[i][0],1.0/values[i]});
            m[equations[i][0]].push_back({equations[i][1],values[i]});
        }
        
        for(auto i:queries){
            if(!m.count(i[0]) || !m.count(i[1])) {
                ans.push_back(-1.0);
                continue;
            }
            unordered_set<string>s;
            ans.push_back(check(i[0],i[1],m,s));
        }
        return ans;
    }
};