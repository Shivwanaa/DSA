class Solution {
public:
    int maximalNetworkRank(int n, vector<vector<int>>& roads) {
        int ans=0;
        set<pair<int,int>>s;
        unordered_map<int,int>in;
        for(auto i:roads){
            in[i[0]]++;
            in[i[1]]++;
            s.insert({i[0],i[1]});
            s.insert({i[1],i[0]});
        }
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(s.find({i,j})!=s.end() || s.find({j,i})!=s.end()){
                    ans=max(ans,in[i]+in[j]-1);
                }
                else{
                    ans=max(ans,in[i]+in[j]);
                }
            }
        }
        return ans;
    }
};