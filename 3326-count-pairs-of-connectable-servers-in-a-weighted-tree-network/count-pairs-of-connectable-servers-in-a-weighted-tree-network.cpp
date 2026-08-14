class Solution {
public:
vector<int>ans;
    int check1(int node,unordered_map<int,vector<pair<int,int>>>&m,int p,int& ss,int d){
        int c=0;
        if(d%ss==0){
            c++;
        }
        for(auto i:m[node]){
            if(i.first!=p){
                c=c+check1(i.first,m,node,ss,d+i.second);
            }
        }
        return c;
    }
    int check(int node,unordered_map<int,vector<pair<int,int>>>&m,int &ss){
        int prev=0;
        int ans=0;
        for(auto i:m[node]){
            int c=check1(i.first,m,node,ss,i.second);
            ans=ans+prev*c;
            prev=prev+c;
        }
        return ans;
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        unordered_map<int,vector<pair<int,int>>>m;
        ans=vector<int>(edges.size()+1,0);
        for(auto i:edges){
            m[i[0]].push_back({i[1],i[2]});
            m[i[1]].push_back({i[0],i[2]});
        }
        for(int i=0;i<=edges.size();i++){
            // if(m[i].size()==1){
            //     continue;
            // }
            // if(ans[i]==0)
            ans[i]=check(i,m,signalSpeed);
        }
        return ans;
    }
};