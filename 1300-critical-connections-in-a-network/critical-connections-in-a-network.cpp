class Solution {
public:
int t=0;
vector<vector<int>>ans;
    void check(int node,unordered_map<int,vector<int>>&m,vector<int>&time,vector<int>&low_time,int p){
        time[node]=++t;
        low_time[node]=t;
        // cout<<node<<" "<<time[node]<<endl;
        for(auto i:m[node]){

            if(i==p){
                continue;
            }
            if(time[i]==0){
                check(i,m,time,low_time,node);
                low_time[node]=min(low_time[node],low_time[i]);
                if(low_time[i]>time[node]){
                ans.push_back({i,node});
            }
            }
            else{
                low_time[node]=min(low_time[node],time[i]);
            }
        }
    }
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<int>time(n,0);
        vector<int>low_time(n,1e9);
        unordered_map<int,vector<int>>m;
        for(auto i:connections){
            m[i[0]].push_back(i[1]);
            m[i[1]].push_back(i[0]);
        }
        check(0,m,time,low_time,0);
        return ans;
    }
};