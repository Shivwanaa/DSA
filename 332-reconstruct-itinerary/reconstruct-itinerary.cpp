class Solution {
public:
    void check(string curr,vector<string>&ans,unordered_map<string,vector<string>>&m,int n){
        while(!m[curr].empty()){
            string temp=m[curr].back();
            m[curr].pop_back();
            check(temp,ans,m,n);
        }
        ans.push_back(curr);
    }
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        vector<string>ans;
        sort(tickets.rbegin(),tickets.rend());
        unordered_map<string,vector<string>>m;
        for(auto i:tickets){
            m[i[0]].push_back(i[1]);
        }
        check("JFK",ans,m,tickets.size()+1);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};