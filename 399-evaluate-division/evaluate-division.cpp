class Solution {
public:
    double check(string n1,string n2,map<pair<string,string>,double>&m,unordered_map<string,vector<string>>&g,unordered_set<string>&v,double a){
        if(g.find(n1)==g.end() || g.find(n2)==g.end()){
            return -1;
        }
        if(n1==n2){
            return a;
        }
        v.insert(n1);
        for(auto i:g[n1]){
            if(v.find(i)==v.end()){
            double ans=check(i,n2,m,g,v,a*m[{n1,i}]);
            if(ans!=-1){
            return ans;
        }
        }
        }
    v.erase(n1);
    return -1;
    }
    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        map<pair<string,string>,double>m;
        int idx=0;
        unordered_map<string,vector<string>>g;
        for(auto i:equations){
            g[i[0]].push_back(i[1]);
            g[i[1]].push_back(i[0]);
            m[{i[0],i[1]}]=double(values[idx]);
            m[{i[1],i[0]}]=double(1.0/double(values[idx]));
            idx++;
        }
        vector<double>ans;
        
        for(auto i:queries){
            unordered_set<string>v;
            ans.push_back(check(i[0],i[1],m,g,v,1.0));
            
        }
        return ans;
}
};