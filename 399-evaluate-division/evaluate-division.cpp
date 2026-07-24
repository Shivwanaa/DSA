class Solution {
public:
    double check(string a,string b,map<pair<string,string>,double>&m,unordered_map<string,vector<pair<string,double>>>&dfs,double temp,unordered_set<string>&v){
        if(dfs.find(a)==dfs.end() ||dfs.find(b)==dfs.end()){
            return -1.0;
        }
        if(a==b){
            return temp;
        }
        v.insert(a);
        for(auto i:dfs[a]){
            if(!v.count(i.first)) {
            double ans = check(
                    i.first,
                    b,
                    m,
                    dfs,
                    temp * i.second,
                    v
                );

                if(ans != -1.0) {
                    return ans;
                }
        }
        }
        v.erase(a);
        return -1.0;
    }


    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
        vector<double>ans;
        map<pair<string,string>,double>m;
        int j=0;
        unordered_map<string,vector<pair<string,double>>>dfs;
        for(auto i:equations){
            m[{i[0],i[1]}]=(values[j]);
            m[{i[1],i[0]}]=(double(1/values[j]));
            dfs[i[0]].push_back({i[1],values[j]});
            dfs[i[1]].push_back({i[0],double(1.0/values[j])});
            j++;
        }
        for(auto i:queries){
            unordered_set<string>v;
            ans.push_back(check(i[0],i[1],m,dfs,1.0,v));
        }
        return ans;
    }
};